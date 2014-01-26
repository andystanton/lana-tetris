
#ifndef __lanaTetris__Alphabet__
#define __lanaTetris__Alphabet__

#include <iostream>
#include <map>
#include "Character.h"

using namespace std;

class Alphabet {
private:
    Alphabet();
    ~Alphabet();
    
    static bool** initaliseArray();
    static Alphabet* alphabet;
    
    map<int, Character*> alphabetMap;
    
    void addToAlphabet(int ascii, Character* character);

public:
    static const int CHARACTER_WIDTH = 5;
    static const int CHARACTER_HEIGHT = 7;
    
    static Alphabet* getInstance();
    
    Character* getChar(int character);
};

#endif /* defined(__lanaTetris__Alphabet__) */
