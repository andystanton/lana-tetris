
#include "Colour.h"

Colour::Colour(const string& name, int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
    
    colour = new GLfloat[3];
    this->colour[0] = r/255.f;
    this->colour[1] = g/255.f;
    this->colour[2] = b/255.f;
    
    this->name = name;
}

Colour::Colour(const string& name, float r, float g, float b) {
    this->r = r*255;
    this->g = g*255;
    this->b = b*255;
    
    colour = new GLfloat[3];
    this->colour[0] = r;
    this->colour[1] = g;
    this->colour[2] = b;

    this->name = name;
}

Colour::Colour(const string& name, int hexValue) {
    r = ((hexValue >> 16) & 0xff);
    g = ((hexValue >> 8) & 0xff);
    b = (hexValue & 0xff);
    
    colour = new GLfloat[3];
    this->colour[0] = r/255.f;
    this->colour[1] = g/255.f;
    this->colour[2] = b/255.f;
    
    this->name = name;
}

GLfloat* Colour::getColour3fv() {
    return colour;
}

Colour::~Colour() {
    delete colour;
    colour = nullptr;
}

float Colour::getR() {
    return r/255.f;
}

float Colour::getG() {
    return g/255.f;
}

float Colour::getB() {
    return b/255.f;
}

string* Colour::toString() {
    return &name;
}
