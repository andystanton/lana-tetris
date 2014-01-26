
#ifndef __lanaTetris__Palette__
#define __lanaTetris__Palette__

#include <iostream>
#include <map>
#include "Colour.h"

using namespace std;

class Palette {
private:
    static Palette* palette;
    map<int, Colour*>* colours;
    Palette();
    ~Palette();
public:
    static const int GREEN = 0, ORANGE = 1, PINK = 2, PURPLE = 3, BLUE = 4, RED = 5, YELLOW = 6, BLACK = 7, WHITE = 8, GREY = 9, NAVY = 10;
    
    static Palette* getInstance();
    void setColour(const int colourAlias, const string& name, int hex);
    Colour* getColour(int);
    int getPrimaryColourCount();
};



#endif /* defined(__lanaTetris__Palette__) */
