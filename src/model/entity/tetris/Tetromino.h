
#ifndef __lanaTetris__Tetromino__
#define __lanaTetris__Tetromino__

#include <iostream>
#include <vector>
#include "TetrominoType.h"  
#include "../Entity.h"
#include "../Drawable.h"
#include "../collision/Collidable.h"
#include "../transformation/Rotation.h"

class Tetromino: public Entity, public Drawable {
public:
    int getRotation();
    TetrominoType* getType();
    Vec2d* getDirection();
    vector<Quad*>* getQuads();
    
    Tetromino* withDirection(Vec2d*);
    
    string* toString();
    
private:
    Tetromino(TetrominoType* type, Vec2d* coords);
    Tetromino(Tetromino*);
    ~Tetromino();
    TetrominoType* type;
    vector<Quad*> quads;
    Vec2d* direction;
    
    friend class TetrominoFactory;
    friend class World;
};

#endif /* defined(__lanaTetris__Tetromino__) */
