
#include "TetrominoType.h"

Colour* TetrominoType::getColour() {
    return this->colour;
}

Vec2d* TetrominoType::getPivotPoint() {
    return pivotPoint;
}

TetrominoType::TetrominoType(char letter, vector<Quad*> quads, Vec2d* pivotPoint, Colour* colour, bool twoState, int displayRotation) {
    this->letter = letter;
    this->quads = quads;
    this->pivotPoint = pivotPoint;
    this->colour = colour;
    this->twoState = twoState;
    this->displayRotation = displayRotation;
}

vector<Quad*>* TetrominoType::getQuads() {
    return &quads;
}

int TetrominoType::getHeight() {
    int minY = 0;
    int maxY = 0;
    for (auto quad : quads) {
        for (int i = 0; i < quad->getVertexCount(); i++) {
            int vertHeight = quad->getVertices()[i]->getY();
            maxY = vertHeight > maxY ? vertHeight : maxY;
            minY = vertHeight < minY ? vertHeight : minY;
        }
    }
    return abs(maxY - minY);
}

char TetrominoType::getLetter() {
    return letter;
}

bool TetrominoType::isTwoState() {
    return twoState;
}

int TetrominoType::getDisplayRotation() {
    return displayRotation;
}

