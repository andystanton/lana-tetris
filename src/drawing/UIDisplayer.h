
#ifndef lanaTetris_UIDisplayer_h
#define lanaTetris_UIDisplayer_h

#include <iomanip>
#include "GLFW/glfw3.h"

#include "TextDisplayer.h"

#include "../model/entity/tetris/World.h"
#include "../model/entity/basic/Alphabet.h"
#include "foundation/Palette.h"


using namespace std;

class UIDisplayer {
private:
    UIDisplayer(GLfloat width, GLfloat height);
    
    static UIDisplayer* uiDisplayer;
    
    GLfloat width, height;

    Palette* palette;
    PrimitiveDisplayer* primitiveDisplayer;
    TextDisplayer* textDisplayer;

    void drawParagraph(const string& text, GLfloat height, GLfloat pixelSize);
    void drawParagraph(const string& text, GLfloat height, GLfloat pixelSize, bool rotateColours);
    void drawParagraphAtCoords(Vec2d coords, const string& text, GLfloat pixelSize, Colour* colour, bool rotateColours);

    GLfloat linebreak(GLfloat height, GLfloat pixelSize);
public:
    static UIDisplayer* getInstance(GLfloat width, GLfloat height);

    void drawStartScreen(void);
    void drawCompleteScreen(void);
    void drawGameplayScreen(World*);
    void drawDeadScreen(long);
};

#endif
