
#include "GameplayDisplayer.h"

GameplayDisplayer* GameplayDisplayer::gameplayDisplayer = nullptr;

GameplayDisplayer* GameplayDisplayer::getInstance() {
    if (gameplayDisplayer == nullptr) {
        gameplayDisplayer = new GameplayDisplayer();
    }
    return gameplayDisplayer;
}

GameplayDisplayer::GameplayDisplayer() {
    palette = Palette::getInstance();
    primitiveDisplayer = PrimitiveDisplayer::getInstance();
}


void GameplayDisplayer::drawPause(GLfloat width) {
    GLint smallSize = primitiveDisplayer->getPixelsPerSquare() / 2;
    GLint pauseHeight = 4;
    
    glColor4f(1.0f, 1.0f, 1.0f, 0.4f);
    
    glPushMatrix();
        glTranslatef(width - smallSize * 3, smallSize * 2, 0.0f);
        for (int i=0; i < pauseHeight; i++) {
            primitiveDisplayer->drawSquare(smallSize);
            glTranslatef(0.0f, smallSize, 0.0f);
        }

        glTranslatef(-2*smallSize, -pauseHeight * smallSize, 0.0f);
        for (int i=0; i < pauseHeight; i++) {
            primitiveDisplayer->drawSquare(smallSize);
            glTranslatef(0.0f, smallSize, 0.0f);
        }
    glPopMatrix();
}

void GameplayDisplayer::drawWorld(World* world) {
    float pps = primitiveDisplayer->getPixelsPerSquare();
    glPushMatrix();
        glTranslatef(pps * 1.f, pps * 1.f, 0.f);
        primitiveDisplayer->drawableWithGLRotation(world->getActiveTet());
        primitiveDisplayer->drawableWithGLRotation(world->getQuadHeap());
    glPopMatrix();
    
}






