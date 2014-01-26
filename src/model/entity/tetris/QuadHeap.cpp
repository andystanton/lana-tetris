
#include "QuadHeap.h"

QuadHeap::QuadHeap(): Entity(Vec2d::ORIGIN, Vec2d::ORIGIN) {
    quads = vector<Quad*>();
    
    for (int x=0; x<10; x++) {
        for (int y=0; y<20; y++) {
            quadState[x][y] = false;
        }
    }
}

QuadHeap::~QuadHeap() {
    Quad::deleteQuads(&quads, false);
}

int QuadHeap::addTet(Tetromino* tet) {
    Vec2d* tetVec = tet->getCoords();
    
    Transformation* rotation = new Rotation(tet->getPivotPoint(), tet->getRotation());
    vector<Quad*>* rotatedQuads = rotation->transform(tet->getQuads());
    
    for (auto quad : *rotatedQuads) {
        quads.push_back(new Quad(quad, tetVec));

        Vec2d** extremities = quad->getExtremities();
        Vec2d* ext = tet->getCoords()->getOffset(extremities[0]);

        quadState[int(ext->getX())][int(ext->getY())] = true;
        
        delete ext;
        delete[] extremities;
    }

    Quad::deleteQuads(rotatedQuads, true);
    delete rotation;

    return cleardown();
}

void QuadHeap::printState(bool world[10][20]) {
    for (int y = 19; y >= 0; y--) {
        for (int x = 0; x < 10; x++) {
            cout << (world[x][y] ? "+" : "-");
        }
        cout << endl;
    }
    cout << endl;
}

void QuadHeap::clearState(bool world[10][20]) {
    for (int y = 19; y >= 0; y--) {
        for (int x = 0; x < 10; x++) {
            world[x][y] = false;
        }
    }
}

int QuadHeap::cleardown() {
    bool rowsToDelete[20] = {false};
    int deletedRowCount = 0;
    for (int y = 0; y < 20; y++) {
        bool hit = true;
        for (int x = 0; x < 10; x++) {
            if (!quadState[x][y]) {
                hit = false;
            }
        }
        if (hit) {
            rowsToDelete[y] = true;
            deletedRowCount++;
        }
    }
    
    auto i = quads.begin();
    
    while (i != quads.end()) {
        Vec2d** extremities = (*i)->getExtremities();
        Vec2d* bottomLeft = extremities[0];

        if (rowsToDelete[int(bottomLeft->getY())]) {
            quadState[int(bottomLeft->getX())][int(bottomLeft->getY())] = false;
            delete *i;
            i = quads.erase(i);
        } else {
            ++i;
        }
        delete[] extremities;
    }

    for (int y = 19; y >= 0; y--) {
        if (rowsToDelete[y]) {
            for (auto quad : quads) {
                Vec2d** extremities = quad->getExtremities();
                Vec2d* bottomLeft = extremities[0];
                int qY = bottomLeft->getY();
                if (qY > y) {
                    for (int v = 0; v < quad->getVertexCount(); v++) {
                        quad->getVertices()[v]->setOffset(Vec2d::SOUTH);
                    }
                }
                delete[] extremities;
            }
        }
    }
    
    clearState(quadState);
    
    for (auto quad : quads) {
        Vec2d** extremities = quad->getExtremities();
        Vec2d* bottomLeft = extremities[0];
        
        int qX = bottomLeft->getX(), qY = bottomLeft->getY();
        quadState[qX][qY] = true;
        
        delete[] extremities;
    }

    return deletedRowCount;
}

vector<Quad*>* QuadHeap::getQuads() {
    return &quads;
}

bool QuadHeap::collidesWithQuads(vector<Quad*>* otherQuads, Vec2d* offset) {
    if (!quads.empty()) {
        for (auto quad : *otherQuads) {
            for (auto heapQuad : quads) {
                if (quad->collidesWithQuad(heapQuad, offset)) {
                    cout << "Collision with Heap" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool QuadHeap::collidesWithQuads(vector<Quad*>* otherQuads) {
    if (!quads.empty()) {
        for (auto quad : *otherQuads) {
            for (auto heapQuad : quads) {
                if (quad->collidesWithQuad(heapQuad)) {
                    cout << "Collision with Heap" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}