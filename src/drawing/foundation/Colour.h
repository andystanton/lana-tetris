
#ifndef __lanaTetris__Colour__
#define __lanaTetris__Colour__

#include <iostream>
#include <string>
#include <sstream>
#include <GLFW/glfw3.h>

using namespace std;

class Colour {
private:
    int r, g, b;
    GLfloat* colour;// = new GLfloat[3];
    string name;
public:
    Colour(const string& name, int r, int g, int b);
    Colour(const string& name, float r, float g, float b);
    Colour(const string& name, int hex);
    ~Colour();
    
    float getR();
    float getG();
    float getB();
    
    GLfloat* getColour3fv();
    
    string* toString();
};

#endif /* defined(__lanaTetris__Colour__) */
