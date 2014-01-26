
#ifndef __lanaTetris__TetrominoType__
#define __lanaTetris__TetrominoType__

#include <vector>
#include "Quad.h"
#include "../../../drawing/foundation/Palette.h"
#include "../../../drawing/foundation/Colour.h"


using namespace std;

class TetrominoType {
private:
    char letter;
    Colour* colour;
    Vec2d* pivotPoint;
    vector<Quad*> quads;
    bool twoState;
    int displayRotation = 0;

    TetrominoType(char, vector<Quad*>, Vec2d*, Colour*, bool, int);
    ~TetrominoType();

public:
    int getHeight();
    char getLetter();
    bool isTwoState();
    Colour* getColour();
    Vec2d* getPivotPoint();
    vector<Quad*>* getQuads();
    int getDisplayRotation();

    friend class TetrominoTypeFactory;
};


#endif /* defined(__lanaTetris__TetrominoType__) */
