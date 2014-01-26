
#include "TransformationData.h"

TransformationData::TransformationData(vector<Quad*>* quads, Vec2d* coords, bool twoState) {
    previousQuads = Quad::cloneQuads(quads);
    previousRotation = 0;
    previousOffset = new Vec2d(coords);
    
    workingQuads = Quad::cloneQuads(quads);
    workingRotation = 0;
    workingOffset = new Vec2d(coords);
    
    this->twoState = twoState;
}

TransformationData::~TransformationData() {
    delete workingOffset;
}

vector<Quad*>* TransformationData::getPreviousQuads() {
    return previousQuads;
}

void TransformationData::setPreviousQuads(vector<Quad*>* previousQuads) {
    Quad::deleteQuads(this->previousQuads, true);
    this->previousQuads = previousQuads;
}

TransformationData* TransformationData::withPreviousQuads(vector<Quad*>* previousQuads) {
    Quad::deleteQuads(this->previousQuads, true);
    this->previousQuads = previousQuads;
    return this;
}

float TransformationData::getPreviousRotation() {
    return previousRotation;
}

void TransformationData::setPreviousRotation(float previousRotation) {
    this->previousRotation = previousRotation;
}

TransformationData* TransformationData::withPreviousRotation(float previousRotation) {
    this->previousRotation = previousRotation;
    return this;
}

Vec2d* TransformationData::getPreviousOffset() {
    return previousOffset;
}

void TransformationData::setPreviousOffset(Vec2d* previousOffset) {
    delete this->previousOffset;
    this->previousOffset = new Vec2d(previousOffset);
}

TransformationData* TransformationData::withPreviousOffset(Vec2d* previousOffset) {
    delete this->previousOffset;
    this->previousOffset = new Vec2d(previousOffset);
    return this;
}

vector<Quad*>* TransformationData::getWorkingQuads() {
    return workingQuads;
}

void TransformationData::setWorkingQuads(vector<Quad*>* workingQuads) {
    Quad::deleteQuads(this->workingQuads, true);
    this->workingQuads = workingQuads;
}

TransformationData* TransformationData::withWorkingQuads(vector<Quad*>* workingQuads) {
    Quad::deleteQuads(this->workingQuads, true);
    this->workingQuads = workingQuads;
    return this;
}

float TransformationData::getWorkingRotation() {
    return workingRotation;
}

void TransformationData::setWorkingRotation(float workingRotation) {
    this->workingRotation = workingRotation;
}

TransformationData* TransformationData::withWorkingRotation(float workingRotation) {
    this->workingRotation = workingRotation;
    return this;
}

Vec2d* TransformationData::getWorkingOffset() {
    return workingOffset;
}

void TransformationData::setWorkingOffset(Vec2d* workingOffset) {
    delete this->workingOffset;
    this->workingOffset = new Vec2d(workingOffset);
}

TransformationData* TransformationData::withWorkingOffset(Vec2d* workingOffset) {
    delete this->workingOffset;
    this->workingOffset = new Vec2d(workingOffset);
    return this;
}

void TransformationData::rollforward() {
    Quad::deleteQuads(previousQuads, true);
    delete previousOffset;
    
    previousQuads = Quad::cloneQuads(workingQuads);
    previousRotation = workingRotation;
    previousOffset = new Vec2d(workingOffset);
}

void TransformationData::rollback() {
    Quad::deleteQuads(workingQuads, true);
    delete workingOffset;
    
    workingQuads = Quad::cloneQuads(previousQuads);
    workingRotation = previousRotation;
    workingOffset = new Vec2d(previousOffset);
}

bool TransformationData::isTwoState() {
    return twoState;
}
