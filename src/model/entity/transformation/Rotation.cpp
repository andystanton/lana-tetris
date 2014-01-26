
#include "Rotation.h"

TransformationType Rotation::getTransformationType() {
    return TransformationType::ROTATION;
}

vector<Quad*>* Rotation::transform(vector<Quad*>* quads) {
    vector<Quad*>* transformedQuads = new vector<Quad*>();
    for (auto quad : *quads) {
        transformedQuads->push_back(quad->getRotatedQuad(pivotPoint, angleRadians));
    }
    return transformedQuads;
}

void Rotation::transform(TransformationData& transformationData) {
    if (transformationData.isTwoState()) {
        angleDegrees = abs(angleDegrees);
        angleRadians = angleDegrees * M_PI / 180;
    }
    
    vector<Quad*>* transformedQuads = new vector<Quad*>();
    for (auto quad : *transformationData.getWorkingQuads()) {
        transformedQuads->push_back(quad->getRotatedQuad(pivotPoint, angleRadians));
    }

    transformationData.rollforward();
    transformationData.setWorkingQuads(transformedQuads);
    transformationData.setWorkingRotation(transformationData.getWorkingRotation() + angleDegrees);
}

Rotation::Rotation(Vec2d* pivotPoint, float angle) {
    this->angleDegrees = angle;
    this->angleRadians = angle * M_PI / 180;
    this->pivotPoint = new Vec2d(pivotPoint);
}

Rotation::~Rotation() {
    delete pivotPoint;
    pivotPoint = nullptr;
}
