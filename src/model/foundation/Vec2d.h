
#ifndef __lanaTetris__Vec2d__
#define __lanaTetris__Vec2d__

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <GLFW/glfw3.h>

using namespace std;

class Vec2d {
private:
    float x;
    float y;
public:
    static Vec2d *NORTH, *SOUTH, *WEST, *EAST, *ORIGIN, *NORTHWEST, *NORTHEAST, *SOUTHWEST, *SOUTHEAST;
    
    enum Operation {
         TRANSLATE
        ,ROTATE
    };

    void setX(float x);
    void setY(float y);

    float getX();
    float getY();
    
    Vec2d* getInverse();
    Vec2d* getInvertX();
    Vec2d* getInvertY();
    Vec2d* getOffset(Vec2d*);
    Vec2d* getRotation(Vec2d*, float);
    Vec2d* getScale(float);

    void setCoords(float x, float y);
    void setCoords(Vec2d* coords);
    void setInverse();
    void setInvertX();
    void setInvertY();
    void setOffset(Vec2d*);
    void setRotation(Vec2d*, float);
    void setRound();
    void setScale(float);
    
    Vec2d* withCoords(float x, float y);
    Vec2d* withCoords(Vec2d* coords);
    Vec2d* withInverse();
    Vec2d* withInvertX();
    Vec2d* withInvertY();
    Vec2d* withOffset(Vec2d*);
    Vec2d* withRotation(Vec2d*, float);
    Vec2d* withRound();
    Vec2d* withScale(float);
    
    bool offsetEquals(Vec2d*, Vec2d*);
    
    Vec2d();
    Vec2d(float x, float y);
    Vec2d(Vec2d* coords);
    
    bool equals(Vec2d* other);
    string toString();
};

#endif /* defined(__lanaTetris__Vec2d__) */
