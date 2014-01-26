
#include "Entity.h"

Entity::Entity(Vec2d* coords, Vec2d* rotationPoint) {
    this->coords = Vec2d(coords);
    this->rotationPoint = Vec2d(rotationPoint);
    rotation = 0;
}

Entity::~Entity() {
}

Vec2d* Entity::getCoords() {
    return &coords;
}

void Entity::setCoords(Vec2d* coords) {
    setCoords(coords->getX(), coords->getY());
}

void Entity::setCoords(float x, float y) {
    coords.setX(x);
    coords.setY(y);
}


void Entity::offsetX(float offset) {
    coords.setX(coords.getX() + offset);
}

void Entity::offsetY(float offset) {
    coords.setY(coords.getY() + offset);
}

void Entity::rotateClockwise() {
    rotation = rotation < 270 ? (rotation + 90) : 0;
    cout << *toString() << endl;
}

void Entity::rotateCounterClockwise() {
    rotation = rotation > 0 ? (rotation - 90) : 270;
    cout << *toString() << endl;
}

void Entity::setRotation(float rotation) {
    float actualRotation = rotation;
    while (actualRotation > 270) {
        actualRotation -= 360;
    }
    while (actualRotation < 0) {
        actualRotation += 360;
    }
    this->rotation = actualRotation;
}

int Entity::getRotation() {
    return rotation;
}

Vec2d* Entity::getPivotPoint() {
    return &rotationPoint;
}

Vec2d* Entity::getAbsolutePivotPoint() {
    return coords.getOffset(&rotationPoint);
}

string* Entity::toString() {
    return new string("Not implemented");
}

