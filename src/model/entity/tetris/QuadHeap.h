
#ifndef __lanaTetris__QuadHeap__
#define __lanaTetris__QuadHeap__

#include <iostream>
#include <vector>
#include "../Entity.h"
#include "../Drawable.h"
#include "Tetromino.h"
#include "../transformation/Rotation.h"
#include "../collision/Collidable.h"

using namespace std;

class QuadHeap: public Entity, public Drawable, public Collidable {
private:
    vector<Quad*> quads;
    bool quadState[10][20];
    
    int cleardown();
    void printState(bool[10][20]);
    void clearState(bool[10][20]);
public:
    QuadHeap();
    ~QuadHeap();
    int addTet(Tetromino*);
    
    vector<Quad*>* getQuads();
    
    bool collidesWithQuads(vector<Quad*>*);
    bool collidesWithQuads(vector<Quad*>*, Vec2d*);
};

#endif /* defined(__lanaTetris__QuadHeap__) */
