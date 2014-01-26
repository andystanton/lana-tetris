
#include "Vec2d.h"

Vec2d* Vec2d::NORTH     = new Vec2d( 0,  1);
Vec2d* Vec2d::SOUTH     = new Vec2d( 0, -1);
Vec2d* Vec2d::WEST      = new Vec2d(-1,  0);
Vec2d* Vec2d::EAST      = new Vec2d( 1,  0);
Vec2d* Vec2d::NORTHEAST = new Vec2d( 1,  1);
Vec2d* Vec2d::NORTHWEST = new Vec2d(-1,  1);
Vec2d* Vec2d::SOUTHEAST = new Vec2d( 1, -1);
Vec2d* Vec2d::SOUTHWEST = new Vec2d(-1, -1);
Vec2d* Vec2d::ORIGIN    = new Vec2d( 0,  0);

Vec2d::Vec2d() {
    setCoords(0, 0);
}

Vec2d::Vec2d(float x, float y) {
    setCoords(x, y);
}

Vec2d::Vec2d(Vec2d* coords) {
    setCoords(coords);
}

Vec2d* Vec2d::getInverse() {
    return new Vec2d(-x, -y);
}

Vec2d* Vec2d::getInvertX() {
    return new Vec2d(-x, y);
}

Vec2d* Vec2d::getInvertY() {
    return new Vec2d(x, -y);
}

Vec2d* Vec2d::getOffset(Vec2d* offset) {
    return new Vec2d(getX() + offset->getX(), getY() + offset->getY());
}

Vec2d* Vec2d::getRotation(Vec2d* rotationPoint, float angle) {
    float s = round(sin(angle));
    float c = round(cos(angle));
    
    // translate point back to origin:
    float rotationX = x - rotationPoint->getX();
    float rotationY = y - rotationPoint->getY();
    
    float xnew = rotationX * c - rotationY * s;
    float ynew = rotationY * c + rotationX * s;
    
    // translate point back:
    return new Vec2d(xnew + rotationPoint->getX(), ynew + rotationPoint->getY());
}

Vec2d* Vec2d::getScale(float scale) {
    return new Vec2d(getX() * scale, getY() * scale);
}

float Vec2d::getX() {
    return this->x;
}

float Vec2d::getY() {
    return this->y;
}

void Vec2d::setCoords(float x, float y) {
    this->x = x;
    this->y = y;
}

void Vec2d::setCoords(Vec2d* coords) {
    this->x = coords->getX();
    this->y = coords->getY();
}

void Vec2d::setOffset(Vec2d* offset) {
    this->x += offset->getX();
    this->y += offset->getY();
}

void Vec2d::setX(float x) {
    this->x = x;
}

void Vec2d::setY(float y) {
    this->y = y;
}

Vec2d* Vec2d::withCoords(float x, float y) {
    this->x = x;
    this->y = y;
    return this;
}

Vec2d* Vec2d::withCoords(Vec2d* coords) {
    withCoords(coords->getX(), coords->getY());
    return this;
}

Vec2d* Vec2d::withInverse() {
    x = -x;
    y = -y;
    return this;
}

Vec2d* Vec2d::withInvertX() {
    x = -x;
    return this;
}

Vec2d* Vec2d::withInvertY() {
    y = -y;
    return this;
}

Vec2d* Vec2d::withOffset(Vec2d* offset) {
    x += offset->getX();
    y += offset->getY();
    return this;
}

Vec2d* Vec2d::withRotation(Vec2d* rotationPoint, float angle) {
    float s = round(sin(angle));
    float c = round(cos(angle));
    
    // translate point back to origin:
    float rotationX = x - rotationPoint->getX();
    float rotationY = y - rotationPoint->getY();
    
    float xnew = rotationX * c - rotationY * s;
    float ynew = rotationY * c + rotationX * s;
    
    // translate point back:
    x = xnew + rotationPoint->getX();
    y = ynew + rotationPoint->getY();
    return this;
}

Vec2d* Vec2d::withRound() {
    this->x = round(x);
    this->y = round(y);
    return this;
}

Vec2d* Vec2d::withScale(float scale) {
    x *= scale;
    y *= scale;
    return this;
}

bool Vec2d::equals(Vec2d *other) {
    return this->x == other->x && this->y == other->y;
}

bool Vec2d::offsetEquals(Vec2d* offset, Vec2d* testVec2d) {
    return (getY() + offset->getY() == testVec2d->getY()) && (getX() + offset->getX() == testVec2d->getX());
}



string Vec2d::toString() {
    return string("(" + to_string(x) + ", " + to_string(y) + ")");
}


