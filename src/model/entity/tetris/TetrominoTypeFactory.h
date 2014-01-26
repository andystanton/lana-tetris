
#ifndef __lanaTetris__TetrominoTypeFactory__
#define __lanaTetris__TetrominoTypeFactory__

#include <map>
#include "TetrominoType.h"
#include "Tetromino.h"
#include "Quad.h"
#include "../../../drawing/foundation/Palette.h"
#include "../../../drawing/foundation/Colour.h"

class TetrominoTypeFactory {
private:
    static TetrominoTypeFactory* tetrominoTypeFactory;
    
    TetrominoTypeFactory();
    ~TetrominoTypeFactory();
    
    TetrominoType* initTetrominoType(  char letter
                                     , Vec2d* quadCoord1
                                     , Vec2d* quadCoord2
                                     , Vec2d* quadCoord3
                                     , Vec2d* quadCoord4
                                     , Vec2d* pivotPoint
                                     , const int colourIndex
                                     , bool twoType = false
                                     , int displayRotation = 0);
    TetrominoType* initI();
    TetrominoType* initO();
    TetrominoType* initT();
    TetrominoType* initJ();
    TetrominoType* initL();
    TetrominoType* initS();
    TetrominoType* initZ();
    TetrominoType* initDebug();
    char getRandomChar();
    
    vector<char> chars;
    map<char, TetrominoType*>* typeMap;
    Palette* palette;

public:
    static TetrominoTypeFactory* getInstance();

    TetrominoType* getRandomType();
    TetrominoType* getType(char);
    
    friend class World;
};

#endif /* defined(__lanaTetris__TetrominoTypeFactory__) */
