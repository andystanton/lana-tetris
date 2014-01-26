
#include "TextDisplayer.h"

TextDisplayer* TextDisplayer::textDisplayer = nullptr;


TextDisplayer* TextDisplayer::getInstance() {
    if (textDisplayer == nullptr) {
        textDisplayer = new TextDisplayer();
    }
    return textDisplayer;
}

TextDisplayer::TextDisplayer() {
    alphabet = Alphabet::getInstance();
    palette = Palette::getInstance();
    primitiveDisplayer = PrimitiveDisplayer::getInstance();
}

void TextDisplayer::drawCharacter(char character, GLint pixelSize) {
    float resetVal = -Alphabet::CHARACTER_HEIGHT * pixelSize;
    if (alphabet->getChar(character)) {
        bool** charValues = alphabet->getChar(character)->getPixels();
        for (int i=0; i<Alphabet::CHARACTER_WIDTH; i++) {
            for (int j=0; j<Alphabet::CHARACTER_HEIGHT; j++) {
                if (charValues[i][j]) {
                    primitiveDisplayer->drawSquare(pixelSize);
                }
                glTranslatef(0.0f, pixelSize, 0.0f);
            }
            glTranslatef(pixelSize, resetVal, 0.0f);
        }
    }
}

void TextDisplayer::writeText(const string& text) {
    writeText(text, primitiveDisplayer->getPixelsPerSquare());
}

void TextDisplayer::writeText(const string& text, GLint pixelSize) {
    writeText(text, pixelSize, false);
}

void TextDisplayer::writeText(const string& text, GLint pixelSize, bool rotateColours) {
    int i = 0;
    for(auto it = text.begin(); it != text.end(); ++it) {
        if (rotateColours) {
            glColor3fv(palette->getColour(i)->getColour3fv());
            if (++i == palette->getPrimaryColourCount()) {
                i = 0;
            }
        }
        drawCharacter(*it, pixelSize);
        glTranslatef(pixelSize, 0.0f, 0.0f);
    }
}

void TextDisplayer::writeCentredParagraph(const string& text, GLfloat width, GLfloat height) {
    writeCentredParagraph(text, width, height, primitiveDisplayer->getPixelsPerSquare());
}

void TextDisplayer::writeCentredParagraph(const string& text, GLfloat width, GLfloat height, GLint pixelSize) {
    writeCentredParagraph(text, width, height, pixelSize, false);
}

void TextDisplayer::writeCentredParagraph(const string& text, GLfloat width, GLfloat height, GLint pixelSize, bool rotateColours) {
    GLint lettersWidth = (GLint) (pixelSize * (text.size() * Alphabet::CHARACTER_WIDTH + text.size() - 1));
    glTranslatef((width-lettersWidth)/2, height - (Alphabet::CHARACTER_HEIGHT * primitiveDisplayer->getPixelsPerSquare()/2), 0.0f);
    TextDisplayer::writeText(text, pixelSize, rotateColours);
}
