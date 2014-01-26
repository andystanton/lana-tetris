
#include "TetrominoTypeFactory.h"

TetrominoTypeFactory* TetrominoTypeFactory::tetrominoTypeFactory = nullptr;

TetrominoTypeFactory* TetrominoTypeFactory::getInstance() {
    if (tetrominoTypeFactory == nullptr) {
        tetrominoTypeFactory = new TetrominoTypeFactory();
    }
    return tetrominoTypeFactory;
}

TetrominoTypeFactory::TetrominoTypeFactory() {
    palette = Palette::getInstance();

    chars = vector<char>();
    chars.push_back('I');
    chars.push_back('O');
    chars.push_back('T');
    chars.push_back('J');
    chars.push_back('L');
    chars.push_back('S');
    chars.push_back('Z');
    
    typeMap = new map<char, TetrominoType*>();
    (*typeMap)['I'] = initI();
    (*typeMap)['O'] = initO();
    (*typeMap)['T'] = initT();
    (*typeMap)['J'] = initJ();
    (*typeMap)['L'] = initL();
    (*typeMap)['S'] = initS();
    (*typeMap)['Z'] = initZ();
    (*typeMap)['D'] = initDebug();
}

TetrominoTypeFactory::~TetrominoTypeFactory() {
    
}

TetrominoType* TetrominoTypeFactory::initTetrominoType(  char name
                                                   , Vec2d* quadCoord1
                                                   , Vec2d* quadCoord2
                                                   , Vec2d* quadCoord3
                                                   , Vec2d* quadCoord4
                                                   , Vec2d* pivotPoint
                                                   , const int colourIndex
                                                   , bool twoState
                                                   , int displayRotation) {

    Colour* fillColour = palette->getColour(colourIndex);
    Colour* lineColour = palette->getColour(Palette::WHITE);
    
    
    vector<Quad*> quads = vector<Quad*>();
    quads.push_back(Quad::getRegularQuad(quadCoord1, fillColour, lineColour));
    quads.push_back(Quad::getRegularQuad(quadCoord2, fillColour, lineColour));
    quads.push_back(Quad::getRegularQuad(quadCoord3, fillColour, lineColour));
    quads.push_back(Quad::getRegularQuad(quadCoord4, fillColour, lineColour));
    
    return new TetrominoType(name, quads, pivotPoint, fillColour, twoState, displayRotation);
}

TetrominoType* TetrominoTypeFactory::initDebug() {
    Colour* grey = palette->getColour(Palette::GREY);
    Colour* black = palette->getColour(Palette::BLACK);
    Colour* white = palette->getColour(Palette::WHITE);
    
    vector<Quad*> quads = vector<Quad*>();
    quads.push_back(Quad::getRegularQuad(new Vec2d(0, 2), white, white));
    quads.push_back(Quad::getRegularQuad(new Vec2d(0, 1), black, white));
    quads.push_back(Quad::getRegularQuad(new Vec2d(0, 0), grey, white));
    
    return new TetrominoType('D', quads, new Vec2d(0.5, 0.5), grey, false, 0);
}

TetrominoType* TetrominoTypeFactory::initI() {
    return initTetrominoType(  'I'
                             
                             , new Vec2d(0, 3)
                             , new Vec2d(0, 2)
                             , new Vec2d(0, 1)
                             , new Vec2d(0, 0)
                             
                             , new Vec2d(0.5, 1.5)
                             , Palette::BLUE
                             , true
                             , 90
    );
}

TetrominoType* TetrominoTypeFactory::initO() {
    return initTetrominoType(  'O'
                             
                             , new Vec2d(0, 1), new Vec2d(1, 1)
                             , new Vec2d(0, 0), new Vec2d(1, 0)
                             
                             , new Vec2d(1, 1)
                             , Palette::PINK
                             , true
                             , 0
    );
}

TetrominoType* TetrominoTypeFactory::initT() {
    return initTetrominoType(  'T'
                             
                             , new Vec2d(-1, 1), new Vec2d(0, 1), new Vec2d(1, 1)
                             , new Vec2d(0, 0)
                             
                             , new Vec2d(0.5, 1.5)
                             , Palette::GREEN
                             , 0
    );
}

TetrominoType* TetrominoTypeFactory::initJ() {
    return initTetrominoType(  'J'
                             
                                              , new Vec2d(1, 2)
                                              , new Vec2d(1, 1)
                             , new Vec2d(0, 0), new Vec2d(1, 0)
                             
                             , new Vec2d(1, 1)
                             , Palette::PURPLE
                             , 0
    );
}

TetrominoType* TetrominoTypeFactory::initL() {
    return initTetrominoType(  'L'
                             
                             , new Vec2d(0, 2)
                             , new Vec2d(0, 1)
                             , new Vec2d(0, 0), new Vec2d(1, 0)
                             
                             , new Vec2d(1, 1)
                             , Palette::YELLOW
                             , 0
    );
}

TetrominoType* TetrominoTypeFactory::initS() {
    return initTetrominoType(  'S'
                             
                                               , new Vec2d(0, 1), new Vec2d(1, 1)
                             , new Vec2d(-1, 0), new Vec2d(0, 0)
                             
                             , new Vec2d(0.5, 0.5)
                             , Palette::RED
                             , true
                             , 0
    );
}

TetrominoType* TetrominoTypeFactory::initZ() {
    return initTetrominoType(  'Z'
                             
                             , new Vec2d(-1, 1), new Vec2d(0, 1)
                                               , new Vec2d(0, 0), new Vec2d(1, 0)
                             
                             , new Vec2d(0.5, 0.5)
                             , Palette::ORANGE
                             , true
                             , 0
    );
}

char TetrominoTypeFactory::getRandomChar() {
    return chars.at(rand() % 7);
}

TetrominoType* TetrominoTypeFactory::getRandomType() {
    auto item = typeMap->find(getRandomChar());
    return item->second;
}

TetrominoType* TetrominoTypeFactory::getType(char letter) {
    auto item = typeMap->find(letter);
    return item->second;
}

