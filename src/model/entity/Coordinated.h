
#ifndef lanaTetris_Coordinated_h
#define lanaTetris_Coordinated_h

#include "../foundation/Vec2d.h"

class Coordinated {
public:
    Coordinated(){}
    virtual ~Coordinated(){}

    virtual Vec2d* getCoords() = 0;
    virtual void setCoords(Vec2d* coords) = 0;
    virtual void setCoords(float x, float y) = 0;
    virtual int getRotation() = 0;
    virtual Vec2d* getPivotPoint() = 0;
    virtual Vec2d* getAbsolutePivotPoint() = 0;
};

#endif
