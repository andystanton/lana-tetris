
#ifndef __lanaTetris__TetrominoFactory__
#define __lanaTetris__TetrominoFactory__

#include "TetrominoTypeFactory.h"
#include "TetrominoType.h"
#include "Tetromino.h"
#include "../../foundation/Vec2d.h"

class TetrominoFactory {
private:
    static TetrominoFactory* tetrominoFactory;

    TetrominoFactory();
    ~TetrominoFactory();
    
    TetrominoTypeFactory* tetrominoTypeFactory;
public:
    static TetrominoFactory* getInstance();
    Tetromino* getRandomTetromino(Vec2d*);
    Tetromino* getTetromino(TetrominoType*, Vec2d*);
    
    friend class World;
};

#endif /* defined(__lanaTetris__TetrominoFactory__) */
