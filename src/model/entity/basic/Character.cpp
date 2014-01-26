
#include "Character.h"

Character::Character(bool** pixels) {
    this->pixels = pixels;
}

bool** Character::getPixels() {
    return this->pixels;
}
