
#ifndef __lanaTetris__World__
#define __lanaTetris__World__

#include <vector>
#include "TetrominoFactory.h"
#include "TetrominoTypeFactory.h"

#include "QuadHeap.h"
#include "../Entity.h"
#include "../collision/Collidable.h"
#include "../transformation/Rotation.h"
#include "../transformation/Translation.h"
#include "../transformation/Pipeline.h"

class World: public Entity, public Collidable {
    
public: enum PlayMode {REGULAR_MODE, INFINITY_MODE, FROZEN_MODE};

private:
    TetrominoFactory* tetFactory;
    TetrominoTypeFactory* typeFactory;
    
    Vec2d* defaultDirection = Vec2d::SOUTH;
    Vec2d* bounds;
    Vec2d* spawnPoint = nullptr;
    Vec2d* gravityDirection;
    
    Tetromino* activeTet = nullptr;
    Tetromino* nextTet = nullptr;
    QuadHeap* heap = nullptr;
    
    vector<Transformation*> inputTransforms;
    
    float gameTime = 0;
    long lastGravityUpdate = 0;
    long gameSpeed = 128;
    
    long infinityGameSpeed = 8192;
    PlayMode mode = REGULAR_MODE;
    
    int score = 0;
    
    void addInput(Transformation*);

public:
    World(Vec2d*, PlayMode);
    ~World();
    
    void start();
    bool tick(float);
    bool resetTet(char);
    bool resetTet(TetrominoType*);
    
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void rotateLeft();
    void rotateRight();
    
    Tetromino* getActiveTet();
    Tetromino* getNextTet();
    QuadHeap* getQuadHeap();
    
    void increaseSpeed();
    void decreaseSpeed();
    
    void setMode(PlayMode);
    
    int getScore();
    
    bool collidesWithQuads(vector<Quad*>*);
    bool collidesWithQuads(vector<Quad*>*, Vec2d*);
};

#endif /* defined(__lanaTetris__World__) */
