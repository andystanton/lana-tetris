
#include "Palette.h"

Palette* Palette::palette;

Palette::Palette() {
    colours = new map<int, Colour*>();
    setColour(GREEN, "Green", 0xAAFF00);
    setColour(ORANGE, "Orange", 0xFFAA00);
    setColour(PINK, "Pink", 0xFF00AA);
    setColour(PURPLE, "Purple", 0xAA00FF);
    setColour(BLUE, "Blue", 0x00AAFF);
    setColour(RED, "Red", 0xFF0036);
    setColour(YELLOW, "Yellow", 0xFFF000);
    setColour(BLACK, "Black", 0x000000);
    setColour(WHITE, "White", 0xFFFFFF);
    setColour(GREY, "Grey", 0x999999);
    setColour(NAVY, "Navy", 0x071865);
}

Palette::~Palette() {
    map<int, Colour*>::iterator it;
    for (it = colours->begin(); it != colours->end();) {
        delete it->second;
        colours->erase(it++);
    }
    delete colours;
    colours = nullptr;
}

void Palette::setColour(const int colourAlias, const string& name, int hex) {
    (*colours)[colourAlias] = new Colour(name, hex);
}

Palette* Palette::getInstance() {
    if (palette == nullptr) {
        palette = new Palette();
    }
    return palette;
}

Colour* Palette::getColour(const int colourAlias) {
    return colours->at(colourAlias);
}

int Palette::getPrimaryColourCount() {
    return 7;
}


