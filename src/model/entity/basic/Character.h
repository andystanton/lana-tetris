
#ifndef __lanaTetris__Character__
#define __lanaTetris__Character__

#include <iostream>

class Character {
private:
    bool** pixels;
public:
    Character(bool**);
    bool** getPixels();
};

#endif /* defined(__lanaTetris__Character__) */
