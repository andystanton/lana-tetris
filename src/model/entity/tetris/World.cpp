
#include "World.h"

World::World(Vec2d* bounds, PlayMode mode): Entity(Vec2d::ORIGIN, Vec2d::ORIGIN) {
    this->bounds = bounds;
    
    setMode(mode);

    typeFactory = TetrominoTypeFactory::getInstance();
    tetFactory = TetrominoFactory::getInstance();
    
    heap = new QuadHeap();
    
    inputTransforms = vector<Transformation*>();
}

World::~World() {
    delete activeTet;
    activeTet = nullptr;
    
    delete nextTet;
    nextTet = nullptr;
    
    delete heap;
    heap = nullptr;
    
    delete spawnPoint;
    spawnPoint = nullptr;
    
    delete bounds;
    bounds = nullptr;
    
    delete typeFactory;
    typeFactory = nullptr;
    
    delete tetFactory;
    tetFactory = nullptr;
}

void World::setMode(PlayMode mode) {
    this->mode = mode;
    
	if (spawnPoint != nullptr) delete spawnPoint;

    switch (mode) {
        case REGULAR_MODE:
            gameSpeed = 128;
            spawnPoint = new Vec2d(bounds->getX()/2, bounds->getY());
            gravityDirection = Vec2d::SOUTH;
            break;
        case INFINITY_MODE:
            gameSpeed = infinityGameSpeed;
            spawnPoint = new Vec2d(bounds->getX()/2, bounds->getY());
            gravityDirection = Vec2d::SOUTH;
            break;
        case FROZEN_MODE:
            gameSpeed = 128;
            spawnPoint = new Vec2d(bounds->getX()/2, bounds->getY()/2);
            gravityDirection = Vec2d::ORIGIN;
            break;
        default:
            break;
    }
}

void World::start() {
    if (heap != nullptr) {
        delete heap;
        heap = new QuadHeap();
    }
    
    lastGravityUpdate = 0;
    resetTet(nullptr);
    resetTet(nullptr);
}

bool World::resetTet(char letter) {
    TetrominoType* type = typeFactory->getType(letter);

    Vec2d* newCoords = new Vec2d(spawnPoint);
    int spawnOffset = type->getHeight();
    newCoords->setY(newCoords->getY() - spawnOffset);
    
    activeTet = tetFactory->getTetromino(type, newCoords)->withDirection(defaultDirection);
    nextTet = tetFactory->getTetromino(type, newCoords)->withDirection(defaultDirection);
    
    return !heap->collidesWithQuads(activeTet->getQuads());
}

bool World::resetTet(TetrominoType* type) {
    Vec2d* newCoords = new Vec2d(spawnPoint);
    if (nextTet == nullptr) {
        TetrominoType* randomType = typeFactory->getRandomType();
        int spawnOffset = randomType->getHeight();
        newCoords->setY(newCoords->getY() - spawnOffset);
        activeTet = tetFactory->getTetromino(randomType, newCoords)->withDirection(defaultDirection);
    } else {
        delete activeTet;
        activeTet = nextTet;
    }

    type = typeFactory->getRandomType();
    int spawnOffset = type->getHeight();
    delete newCoords;

    newCoords = new Vec2d(spawnPoint);
    if (mode == INFINITY_MODE) newCoords->setX((rand() % 8) + 1);
    newCoords->setY(newCoords->getY() - spawnOffset);
    nextTet = tetFactory->getTetromino(type, newCoords)->withDirection(defaultDirection);
    
    Translation translation = Translation(activeTet->getCoords());
    
    vector<Quad*>* resetQuads = translation.transform(activeTet->getQuads());
    bool success = !heap->collidesWithQuads(resetQuads);
    
    Quad::deleteQuads(resetQuads, true);

    delete newCoords;
    
    return success;
}

Tetromino* World::getActiveTet() {
    return activeTet;
}

Tetromino* World::getNextTet() {
    return nextTet;
}

QuadHeap* World::getQuadHeap() {
    return heap;
}

void World::addInput(Transformation* transformation) {
    inputTransforms.push_back(transformation);
}

bool World::tick(float gameTime) {
    bool playing = true;
    this->gameTime = gameTime;
    
    long gravityTick = trunc((gameTime * gameSpeed) / 128);
    
    Pipeline pipeline = Pipeline(activeTet);
    
    pipeline.addCollidable(this);
    pipeline.addCollidable(heap);
    
    pipeline.addTransformation(new Rotation(activeTet->getPivotPoint(), activeTet->getRotation()));
    
    if (gravityTick > lastGravityUpdate) {
        lastGravityUpdate = gravityTick;
        pipeline.addTransformation(new Translation(gravityDirection));
    }
    
    pipeline.addTransformations(&inputTransforms);
    
    inputTransforms.clear();
    
    PipelineResult* result = pipeline.execute();

    activeTet->setRotation(result->getNetRotation());
    activeTet->setCoords(result->getNetOffset());

    bool dead = result->isDead();

    delete result;
    
    if (dead) {
        int rows = heap->addTet(activeTet);
        
        switch (rows) {
            case 1:
                score += 50;
                break;
            case 2:
                score += 100;
                break;
            case 3:
                score += 200;
                break;
            case 4:
                score += 500;
                break;
            default:
                break;
        }
        
        if (!resetTet(nullptr)) {
            playing = false || mode == INFINITY_MODE;
            
            delete heap;
            heap = new QuadHeap();
        }
    }
    
    return playing;
}

// TODO: rather than calculating offset off each coord, test against negative offset applied to bounds?
bool World::collidesWithQuads(vector<Quad*>* quads, Vec2d* offset) {
    for (auto quad : *quads) {
        for (int i = 0; i < quad->getVertexCount(); i++) {
            Vec2d* vertex = quad->getVertices()[i]->getOffset(offset);
            if (vertex->getY() < 0 || vertex->getY() > bounds->getY() || vertex->getX() < 0 || vertex->getX() > bounds->getX()) {
                cout << "Collision with world " << vertex->toString() << endl;
                delete vertex;
                return true;
            }
            delete vertex;
        }
    }
    return false;
}

bool World::collidesWithQuads(vector<Quad*>* quads) {
    for (auto quad : *quads) {
        for (int i = 0; i < quad->getVertexCount(); i++) {
            Vec2d* vertex = quad->getVertices()[i];
            if (vertex->getY() < 0 || vertex->getY() > bounds->getY() || vertex->getX() < 0 || vertex->getX() > bounds->getX()) {
                cout << "Collision with world " << vertex->toString() << endl;
                return true;
            }
        }
    }
    return false;
}

int World::getScore() {
    return score;
}

void World::increaseSpeed() {
    if (gameSpeed * 2 <= 32768) {
        gameSpeed *= 2;
        lastGravityUpdate = trunc((gameTime * gameSpeed) / 128);
        float speedPercentage = 100.f * gameSpeed / 128;
        cout << "game speed is now " << speedPercentage << " (" << speedPercentage / 100 << "x)" << endl;
    }
}

void World::decreaseSpeed() {
    if ((gameSpeed / 2) % 2 == 0) {
        gameSpeed /= 2;
        lastGravityUpdate = trunc((gameTime * gameSpeed) / 128);
        float speedPercentage = 100.f * gameSpeed / 128;
        cout << "game speed is now " << speedPercentage << " (" << speedPercentage / 100 << "x)" << endl;
    }
}

void World::moveLeft() {
    addInput(new Translation(Vec2d::WEST));
}

void World::moveRight() {
    addInput(new Translation(Vec2d::EAST));
}

void World::moveUp() {
    if (mode == PlayMode::FROZEN_MODE) {
        addInput(new Translation(Vec2d::NORTH));
    }
}

void World::moveDown() {
    addInput(new Translation(Vec2d::SOUTH));
}

void World::rotateLeft() {
    addInput(new Rotation(activeTet->getPivotPoint(),-90));
}

void World::rotateRight() {
    addInput(new Rotation(activeTet->getPivotPoint(), 90));
}

