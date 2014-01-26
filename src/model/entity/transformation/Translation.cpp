
#include "Translation.h"

Translation::Translation(Vec2d* direction) {
    this->direction = new Vec2d(direction);
}

TransformationType Translation::getTransformationType() {
    return TransformationType::TRANSLATION;
}

vector<Quad*>* Translation::transform(vector<Quad*>* quads) {
    vector<Quad*>* transformedQuads = new vector<Quad*>();
    for (auto quad : *quads) {
        transformedQuads->push_back(new Quad(quad, direction));
    }
    return transformedQuads;
}

void Translation::transform(TransformationData& transformationData) {
    transformationData.rollforward();
    Vec2d* newOffset = transformationData.getWorkingOffset()->getOffset(direction);
    transformationData.setWorkingOffset(newOffset);
    delete newOffset;
}

Translation::~Translation() {
    delete direction;
    direction = nullptr;
}

Vec2d* Translation::getTranslationVector() {
    return direction;
}