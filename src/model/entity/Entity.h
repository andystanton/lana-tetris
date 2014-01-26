
#ifndef __lanaTetris__Entity__
#define __lanaTetris__Entity__

#include <GLFW/glfw3.h>
#include "../foundation/Vec2d.h"
#include "Coordinated.h"

using namespace std;

class Entity: public virtual Coordinated {
protected:
    int rotation;
    Vec2d coords;
    Vec2d rotationPoint;
    
public:
    Entity(Vec2d*, Vec2d*);
    ~Entity();
    
    virtual int getRotation();
    Vec2d* getCoords();
    Vec2d* getPivotPoint();
    Vec2d* getAbsolutePivotPoint();

    void setCoords(float x, float y);
    void setCoords(Vec2d* coords);

    void offsetX(float);
    void offsetY(float);
    
    void rotateClockwise();
    void rotateCounterClockwise();
    
    void setRotation(float rotation);

    virtual string* toString();
};

#endif /* defined(__lanaTetris__Entity__) */
