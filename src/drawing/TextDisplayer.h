
#ifndef __lanaTetris__TextDisplayer__
#define __lanaTetris__TextDisplayer__

#include <string>
#include "GLFW/glfw3.h"

#include "PrimitiveDisplayer.h"

#include "foundation/Palette.h"
#include "../model/entity/basic/Alphabet.h"

using namespace std;

class TextDisplayer {
private:
    TextDisplayer();

    static TextDisplayer* textDisplayer;
    
    Palette* palette;
    PrimitiveDisplayer* primitiveDisplayer;
    Alphabet* alphabet;
public:
    static TextDisplayer* getInstance();
    void drawCharacter(char character, GLint pixelSize);
    void writeText(const string& text, GLint pixelSize, bool rotateColours);
    void writeText(const string& text, GLint pixelSize);
    void writeText(const string& text);
    void writeCentredParagraph(const string& text, GLfloat width, GLfloat height, GLint pixelSize, bool rotateColours);
    void writeCentredParagraph(const string& text, GLfloat width, GLfloat height, GLint pixelSize);
    void writeCentredParagraph(const string& text, GLfloat width, GLfloat height);
};

#endif /* defined(__lanaTetris__Text__) */
