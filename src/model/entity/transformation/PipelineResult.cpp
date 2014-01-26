
#include "PipelineResult.h"

PipelineResult::PipelineResult(vector<Quad*>* quads, bool dead, float netRotation, Vec2d* netOffset) {
    this->quads = new vector<Quad*>();
    for (auto quad : *quads) {
        this->quads->push_back(new Quad(quad));
    }
    this->dead = dead;
    this->netRotation = netRotation;
    this->netOffset = new Vec2d(netOffset);
}

PipelineResult::PipelineResult(TransformationData& transformationData, bool dead) {
    this->quads = transformationData.getWorkingQuads();
    this->dead = dead;
    this->netRotation = transformationData.getWorkingRotation();
    this->netOffset = new Vec2d(transformationData.getWorkingOffset());
}

PipelineResult::~PipelineResult() {
    Quad::deleteQuads(quads, true);
    delete netOffset;
}

vector<Quad*>* PipelineResult::getQuads() {
    return quads;
}

bool PipelineResult::isDead() {
    return dead;
}

float PipelineResult::getNetRotation() {
    return netRotation;
}

Vec2d* PipelineResult::getNetOffset() {
    return netOffset;
}