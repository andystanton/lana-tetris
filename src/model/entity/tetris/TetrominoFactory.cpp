
#include "TetrominoFactory.h"

TetrominoFactory* TetrominoFactory::tetrominoFactory = nullptr;

TetrominoFactory* TetrominoFactory::getInstance() {
    if (tetrominoFactory == nullptr) {
        tetrominoFactory = new TetrominoFactory();
    }
    return tetrominoFactory;
}

TetrominoFactory::TetrominoFactory() {
    tetrominoTypeFactory = TetrominoTypeFactory::getInstance();
}

TetrominoFactory::~TetrominoFactory() {
    
}

Tetromino* TetrominoFactory::getRandomTetromino(Vec2d* coords) {
    TetrominoType* type = tetrominoTypeFactory->getRandomType();
    return new Tetromino(type, coords);
}

Tetromino* TetrominoFactory::getTetromino(TetrominoType* type, Vec2d* coords) {
    return new Tetromino(type, coords);
}