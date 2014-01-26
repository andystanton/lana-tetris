
#ifndef lanaTetris_Collidable_h
#define lanaTetris_Collidable_h

#include <vector>
#include "../tetris/Quad.h"

class Collidable {
public:
    enum CollisionType {NONE = 0, RESTRICT = 1, HALT = 2};
    virtual bool collidesWithQuads(vector<Quad*>*) = 0;
    virtual bool collidesWithQuads(vector<Quad*>*, Vec2d*) = 0;
};

#endif
