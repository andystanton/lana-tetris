
#include "Pipeline.h"

Pipeline::Pipeline(Tetromino* transformee) {
    this->transformee = transformee;
    this->pipeline = new vector<Transformation*>();
    this->collidables = new vector<Collidable*>();
}

Pipeline::~Pipeline() {
    for (auto transformation : *pipeline) {
        delete transformation;
    }
    
    pipeline->clear();
    delete pipeline;
    pipeline = nullptr;
    
    collidables->clear();
    delete collidables;
    collidables = nullptr;
}

void Pipeline::addTransformations(vector<Transformation*>* transformations) {
    for (auto transformation : *transformations) {
        addTransformation(transformation);
    }
}

void Pipeline::addTransformation(Transformation* transformation) {
    pipeline->push_back(transformation);
}

void Pipeline::addCollidable(Collidable* collidable) {
    collidables->push_back(collidable);
}

PipelineResult* Pipeline::execute() {
    TransformationData pipelineData = TransformationData(transformee->getQuads(), transformee->getCoords(), transformee->getType()->isTwoState());

    bool halt = false;
    for (auto transformation : *pipeline) {
        transformation->transform(pipelineData);
        switch (hitCollidable(pipelineData, transformation)) {
            case Collidable::RESTRICT:
                pipelineData.rollback();
                break;
            case Collidable::HALT:
                pipelineData.rollback();
                halt = true;
                break;
            case Collidable::NONE:
            default:
                break;
        }
        if (halt) break;
    }
    
    Quad::deleteQuads(pipelineData.getPreviousQuads(), true);
    delete pipelineData.getPreviousOffset();

    return new PipelineResult(pipelineData, halt);
}

Collidable::CollisionType Pipeline::hitCollidable(TransformationData& pipelineData, Transformation* transformation) {
    bool collided = false;
    Collidable::CollisionType type = Collidable::NONE;
    Collidable* collider = nullptr;
    for (auto collidable : *collidables) {
        if (collidable->collidesWithQuads(pipelineData.getWorkingQuads(), pipelineData.getWorkingOffset())) {
            collider = collidable;
            collided = true;
            type = Collidable::CollisionType::RESTRICT;
        }
    }
    
    if (collided && transformation->getTransformationType() == TransformationType::TRANSLATION) {
        Translation* tl = static_cast<Translation*>(transformation);
        if (tl->getTranslationVector()->equals(Vec2d::SOUTH)) {
            type = Collidable::CollisionType::HALT;
        }
    }
    
    return type;
}

