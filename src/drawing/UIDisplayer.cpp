
#include "UIDisplayer.h"

UIDisplayer* UIDisplayer::uiDisplayer = nullptr;

UIDisplayer* UIDisplayer::getInstance(GLfloat width, GLfloat height) {
    if (uiDisplayer == nullptr) {
        uiDisplayer = new UIDisplayer(width, height);
    }
    return uiDisplayer;
}

UIDisplayer::UIDisplayer(GLfloat width, GLfloat height) {
    UIDisplayer::width = width;
    UIDisplayer::height = height;
    
    palette = Palette::getInstance();
    primitiveDisplayer = PrimitiveDisplayer::getInstance();
    textDisplayer = TextDisplayer::getInstance();
}

void UIDisplayer::drawParagraph(const string& text, GLfloat height, GLfloat pixelSize) {
    return drawParagraph(text, height, pixelSize, false);
}

void UIDisplayer::drawParagraph(const string& textToDisplay, GLfloat height, GLfloat pixelSize, bool rotateColours) {
    glPushMatrix();
        glColor3fv(palette->getColour(Palette::GREEN)->getColour3fv());
        textDisplayer->writeCentredParagraph(textToDisplay, width, height, pixelSize, rotateColours);
    glPopMatrix();
}

void UIDisplayer::drawParagraphAtCoords(Vec2d coords, const string& textToDisplay, GLfloat pixelSize, Colour* colour, bool rotateColours) {
    glPushMatrix();
        glTranslatef(coords.getX(), coords.getY(), 0.f);
        glColor3fv(colour->getColour3fv());
        textDisplayer->writeText(textToDisplay, pixelSize, rotateColours);
    glPopMatrix();
}

GLfloat UIDisplayer::linebreak(GLfloat height, GLfloat pixelSize) {
    return height + pixelSize * (Alphabet::CHARACTER_HEIGHT + 1.5);
}

void UIDisplayer::drawStartScreen(void) {
    GLfloat rectWidth = 29;
    GLfloat rectHeight = 10;

    glPushMatrix();
        glTranslatef((width - rectWidth * 20) / 2, 7.5 + (height - rectHeight * 20)/2, 0);
        primitiveDisplayer->drawRectangleOutline(20, rectWidth, rectHeight, palette->getColour(Palette::GREEN));
    glPopMatrix();
    
    drawParagraph("TETRIS", height/2 + 35, 15, true);
    drawParagraph("PRESS SPACE TO START", linebreak(height/2 + 35, 15), 4);
}

void UIDisplayer::drawGameplayScreen(World* world) {
    GLfloat blockSize = 30;

    Colour* borderColour = palette->getColour(Palette::WHITE);
    Colour* shapeColour = palette->getColour(Palette::ORANGE);
    Colour* shapeLineColour = palette->getColour(Palette::WHITE);
    
    // field
    primitiveDisplayer->drawRectangleOutline(Vec2d(blockSize, blockSize), Vec2d(10 * blockSize, 20 * blockSize), borderColour);
    
    //grid
    glPushMatrix();
        glColor4f(1.f, 1.f, 1.f, 0.5f);
        glTranslatef(1, 1, 0);
        for (int i = 1; i < 10; i++) {
            glPushMatrix();
                glTranslatef(blockSize, 0, 0);
                glLineWidth((i%5==0) ? 5 : 0.5);
                glBegin(GL_LINES);
                    glVertex2f(i*blockSize, blockSize);
                    glVertex2f(i*blockSize, 21 * blockSize);
                glEnd();
            glPopMatrix();
        }
        for (int i = 1; i < 20; i++) {
            glPushMatrix();
                glTranslatef(0, blockSize, 0);
                glLineWidth((i%5==0) ? 5 : 0.5);
                glBegin(GL_LINES);
                    glVertex2f(blockSize, i*blockSize);
                    glVertex2f(11*blockSize, i* blockSize);
                glEnd();
            glPopMatrix();
        }
    glPopMatrix();
    
    // next shape
    primitiveDisplayer->drawRectangleOutline(Vec2d(12 * blockSize, blockSize), Vec2d(9 * blockSize, 4 * blockSize), borderColour);
    drawParagraphAtCoords(Vec2d(12 * blockSize + 12, blockSize + 14), "NEXT", 4, palette->getColour(Palette::PINK), false);
    
    glPushMatrix();
        Vec2d* newShapePos = new Vec2d(0, 20);
        glTranslatef(17 * blockSize, 4.5 * blockSize, 0.f);
        primitiveDisplayer->drawableWithGLRotation(world->getNextTet(), world->getNextTet()->getType()->getDisplayRotation(), newShapePos);
        delete newShapePos;
        newShapePos = nullptr;
    glPopMatrix();

    
    // score
    primitiveDisplayer->drawRectangleOutline(Vec2d(12 * blockSize, 6 * blockSize), Vec2d(9 * blockSize, 4 * blockSize), borderColour);
    drawParagraphAtCoords(Vec2d(12 * blockSize + 12, 6 * blockSize + 14), "SCORE", 4, palette->getColour(Palette::PINK), false);
    
    stringstream ss;
    ss << setw(6) << setfill('0') << world->getScore();
    drawParagraphAtCoords(Vec2d(12 * blockSize + 12, 7 * blockSize + 26), ss.str(), 7, palette->getColour(Palette::GREEN), true);
    
    // logo
    primitiveDisplayer->drawRectangleOutline(Vec2d(12 * blockSize, 17 * blockSize), Vec2d(9 * blockSize, 4 * blockSize), borderColour);
    drawParagraphAtCoords(Vec2d(12 * blockSize + 88, 17 * blockSize + 14), "LANA", 4, palette->getColour(Palette::PINK), false);
    drawParagraphAtCoords(Vec2d(12 * blockSize + 12, 18 * blockSize + 26), "TETRIS", 7, palette->getColour(Palette::GREEN), true);
    
    borderColour = nullptr;
    shapeColour = nullptr;
    shapeLineColour = nullptr;
}

