
#include "Quad.h"

Quad::Quad() {
    vertices = new Vec2d*[4];
}

Quad::Quad(Quad* quadToCopy)    {
    vertices = new Vec2d*[4];
    
    vertexCount = quadToCopy->getVertexCount();
    fillColour = quadToCopy->getFillColour();
    lineColour = quadToCopy->getLineColour();
    Vec2d** verticesToCopy = quadToCopy->getVertices();
    for (int i = 0; i < 4; i++) {
        vertices[i] = new Vec2d(verticesToCopy[i]);
    }
    verticesToCopy = nullptr;
}

Quad::Quad(Quad* quadToCopy, Vec2d* offset)    {
    vertices = new Vec2d*[4];
    
    vertexCount = quadToCopy->getVertexCount();
    fillColour = quadToCopy->getFillColour();
    lineColour = quadToCopy->getLineColour();
    Vec2d** verticesToCopy = quadToCopy->getVertices();
    for (int i = 0; i < 4; i++) {
        vertices[i] = (new Vec2d(verticesToCopy[i]))->withOffset(offset);
    }
    verticesToCopy = nullptr;
    offset = nullptr;
    quadToCopy = nullptr;
}

Quad::~Quad() {
    for (int i = 0; i < vertexCount; i++) {
        delete vertices[i];
    }
    delete[] vertices;
    vertices = nullptr;
}

Vec2d** Quad::getVertices() {
    return vertices;
}

Colour* Quad::getFillColour() {
    return this->fillColour;
}

Colour* Quad::getLineColour() {
    return this->lineColour;
}

int Quad::getVertexCount() {
    return this->vertexCount;
}

Quad* Quad::withVertex(Vec2d* vertex) {
    vertices[vertexCount++] = vertex;
    return this;
}

Quad* Quad::withFillColour(Colour* fillColour) {
    this->fillColour = fillColour;
    return this;
}

Quad* Quad::withLineColour(Colour* lineColour) {
    this->lineColour = lineColour;
    return this;
}

string* Quad::toString() {
    Vec2d** extremities = getExtremities();
    string* extremitiesString = new string(extremities[0]->toString() + " -> " + extremities[1]->toString());
    string* quadString = new string(" - QUAD (" + to_string(vertexCount) + " vertices, Extremities: " + *extremitiesString + "):\n");
    for (int i=0; i < vertexCount; i++) {
        *quadString += "   - ";
        *quadString += vertices[i]->toString();
        *quadString += "\n";
    }
    delete[] extremities;
    extremities = nullptr;
    return quadString;
}

float* Quad::toVertices(float scale) {
    float* floatVertices = new float[8];
    
    for (int i=0; i < 8; i+=2) {
        Vec2d* rotatedCoord = vertices[i/2]->getScale(scale);
        
        floatVertices[i]   = rotatedCoord->getX();
        floatVertices[i+1] = rotatedCoord->getY();
        
        delete rotatedCoord;
        rotatedCoord = nullptr;
    }
    
    return floatVertices;
}

float* Quad::toVerticesWithInvertedY(float scale) {
    float* floatVertices = new float[8];
    
    for (int i=0; i < 8; i+=2) {
        Vec2d* rotatedCoord = vertices[i/2]->getScale(scale);
        
        floatVertices[i]   =  rotatedCoord->getX();
        floatVertices[i+1] = -rotatedCoord->getY();
        
        delete rotatedCoord;
        rotatedCoord = nullptr;
    }
    
    return floatVertices;
}

float* Quad::toRotatedVertices(float scale, Vec2d* pivotPoint, float pivotAngle) {
    float* rotatedVertices = new float[8];
    
    for (int i=0; i < 8; i+=2) {
        Vec2d* rotatedCoord = vertices[i/2]->getRotation(pivotPoint, -pivotAngle)->withScale(scale);
        
        rotatedVertices[i]   = rotatedCoord->getX();
        rotatedVertices[i+1] = rotatedCoord->getY();
        
        delete rotatedCoord;
        rotatedCoord = nullptr;
    }
    
    return rotatedVertices;
}

float* Quad::toRotatedVerticesWithInvertedY(float scale, Vec2d* pivotPoint, float pivotAngle) {
    float* rotatedVertices = new float[8];
    
    for (int i=0; i < 8; i+=2) {
        Vec2d* rotatedCoord = vertices[i/2]->getRotation(pivotPoint, -pivotAngle)->withScale(scale);
        
        rotatedVertices[i]   =  rotatedCoord->getX();
        rotatedVertices[i+1] = -rotatedCoord->getY();
        
        delete rotatedCoord;
        rotatedCoord = nullptr;
    }
    
    return rotatedVertices;
}

Quad* Quad::getRotatedQuad(Vec2d* pivotPoint, float pivotAngle) {
    Quad* rotatedQuad = new Quad(this);
    
    for (int i=0; i < 4; i++) {
        rotatedQuad->getVertices()[i]->withRotation(pivotPoint, -pivotAngle);
    }
    
    return rotatedQuad;
}

Vec2d** Quad::getExtremities() {
    Vec2d** extremities = new Vec2d*[2];
    bool initialised = false;
    for (int i = 0; i < vertexCount; i++) {
        Vec2d* vec = vertices[i];
        if (!initialised) {
            extremities[0] = vec;
            extremities[1] = vec;
            initialised = true;
        } else {
            if (vec->getX() <= extremities[0]->getX() && vec->getY() <= extremities[0]->getY()) {
                extremities[0] = vec;
            }
            if (vec->getX() >= extremities[1]->getX() && vec->getY() >= extremities[1]->getY()) {
                extremities[1] = vec;
            }
        }
        vec = nullptr;
    }
    return extremities;
}

bool Quad::collidesWithQuad(Quad* other) {
    Vec2d** myExtremities = getExtremities();
    Vec2d** theirExtremities = other->getExtremities();
    bool collision = myExtremities[0]->equals(theirExtremities[0]) && myExtremities[1]->equals(theirExtremities[1]);

    delete[] myExtremities;
    delete[] theirExtremities;
    myExtremities = nullptr;
    theirExtremities = nullptr;

    return collision;
}

bool Quad::collidesWithQuad(Quad* other, Vec2d* offset) {
    Vec2d** myExtremities = getExtremities();
    Vec2d** theirExtremities = other->getExtremities();
    bool collision =  myExtremities[0]->offsetEquals(offset, theirExtremities[0]) && myExtremities[1]->offsetEquals(offset, theirExtremities[1]);
    
    delete[] myExtremities;
    delete[] theirExtremities;
    myExtremities = nullptr;
    theirExtremities = nullptr;
    
    return collision;
}

Quad* Quad::getRegularQuad(Vec2d* startCoord, Colour* fillColour, Colour* lineColour) {
    return (new Quad())
        ->withFillColour(fillColour)
        ->withLineColour(lineColour)
        ->withVertex(startCoord)
        ->withVertex(startCoord->getOffset(Vec2d::NORTH))
        ->withVertex(startCoord->getOffset(Vec2d::NORTHEAST))
        ->withVertex(startCoord->getOffset(Vec2d::EAST));
}

void Quad::deleteQuads(vector<Quad*>* quads, bool and1) {
    for (int i=0; i<quads->size(); i++) {
        delete (*quads)[i];
    }
    quads->clear();
    if (and1) delete quads;
}

vector<Quad*>* Quad::cloneQuads(vector<Quad*>* quads) {
    vector<Quad*>* clonedQuads = new vector<Quad*>();
    for (auto quad : *quads) {
        clonedQuads->push_back(new Quad(quad));
    }
    return clonedQuads;
}

