
#ifndef lanaTetris_Drawable_h
#define lanaTetris_Drawable_h

#include <vector>
#include "Coordinated.h"
#include "tetris/Quad.h"

class Drawable: public virtual Coordinated {
public:
    Drawable(){}
    virtual ~Drawable(){}
    
    virtual vector<Quad*>* getQuads() = 0;
};

#endif
