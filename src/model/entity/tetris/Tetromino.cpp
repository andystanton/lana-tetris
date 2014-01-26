
#include "Tetromino.h"

Tetromino::Tetromino(TetrominoType* type, Vec2d* coords): Entity(coords, type->getPivotPoint()) {
    this->type = type;
    for (auto quad : *type->getQuads()) {
        quads.push_back(new Quad(quad));
    }
    withDirection(Vec2d::ORIGIN);
}

Tetromino::Tetromino(Tetromino* tetToCopy): Entity(tetToCopy->getCoords(), tetToCopy->getType()->getPivotPoint()) {
    this->type = tetToCopy->getType();
    for (auto quad : *type->getQuads()) {
        quads.push_back(new Quad(quad));
    }
    withDirection(tetToCopy->getDirection());
}

Tetromino::~Tetromino() {
    Quad::deleteQuads(&quads, false);
}

TetrominoType* Tetromino::getType() {
    return type;
}

vector<Quad*>* Tetromino::getQuads() {
    return &quads;
}

Tetromino* Tetromino::withDirection(Vec2d* direction) {
    this->direction = direction;
    return this;
}

Vec2d* Tetromino::getDirection() {
    return direction;
}

int Tetromino::getRotation() {
    return ((type->isTwoState() && rotation > 90) ? rotation - 180 : rotation);
}

string* Tetromino::toString() {
    Transformation* rotationT = new Rotation(&rotationPoint, rotation);
    vector<Quad*>* rotatedQuads = rotationT->transform(&quads);
    
    string* tetString = new string("TETROMINO ("
                                   + to_string(rotation)
                                   + " degrees, "
                                   + to_string(rotatedQuads->size())
                                   + " quads, two state: "
                                   + to_string(type->isTwoState())
                                   + "):\n");

    for (auto quad : *rotatedQuads) {
        *tetString += *quad->toString();
    }
    *tetString += "\n";
    
    Quad::deleteQuads(rotatedQuads, true);
    
    delete rotationT;
    rotationT = nullptr;

    return tetString;
}
