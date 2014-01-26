
#ifndef __lanaTetris__GameplayDisplayer__
#define __lanaTetris__GameplayDisplayer__

#include "GLFW/glfw3.h"
#include "PrimitiveDisplayer.h"
#include "../model/entity/tetris/Tetromino.h"
#include "../model/entity/tetris/TetrominoType.h"
#include "../model/entity/tetris/QuadHeap.h"
#include "../model/entity/tetris/World.h"

class GameplayDisplayer {
private:
    Palette* palette;
    PrimitiveDisplayer* primitiveDisplayer;
    int pixelSize = 30;
    static GameplayDisplayer* gameplayDisplayer;
    GameplayDisplayer();
public:
    static GameplayDisplayer* getInstance();
    void drawPause(GLfloat width);
    void drawWorld(World* world);
};

#endif /* defined(__lanaTetris__GameplayDisplayer__) */
