
#include "PrimitiveDisplayer.h"

PrimitiveDisplayer* PrimitiveDisplayer::primitiveDisplayer = nullptr;

PrimitiveDisplayer* PrimitiveDisplayer::getInstance() {
    if (primitiveDisplayer == nullptr) {
        primitiveDisplayer = new PrimitiveDisplayer(30);
    }
    return primitiveDisplayer;
}

PrimitiveDisplayer::PrimitiveDisplayer(GLfloat pixelsPerSquare) {
    this->pixelsPerSquare = pixelsPerSquare;
    verticesVec = new Vec2d*[4] {
        Vec2d::ORIGIN,
        Vec2d::EAST,
        Vec2d::SOUTHEAST,
        Vec2d::SOUTH
    };
}

void PrimitiveDisplayer::drawSquare() {
    drawSquare(pixelsPerSquare);
}

GLfloat PrimitiveDisplayer::getPixelsPerSquare() {
    return pixelsPerSquare;
}

void PrimitiveDisplayer::drawSquare(GLfloat pixelSize) {
    glShadeModel(GL_FLAT);
    GLfloat vertices[8] = {
        0           ,0
        ,pixelSize  ,0
        ,pixelSize  ,pixelSize
        ,0          ,pixelSize
    };
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}



GLfloat* PrimitiveDisplayer::getRotatedVertices(GLfloat blockSize, float angle) {
    GLfloat* vertices = new GLfloat[8];
    
    for (int i=0; i < 8; i+=2) {
        Vec2d* rotatedCoord = verticesVec[i/2]->getRotation(Vec2d::ORIGIN, angle)->withScale(blockSize);
        
        vertices[i] = rotatedCoord->getX();
        vertices[i+1] = rotatedCoord->getY();
        
        delete rotatedCoord;
        rotatedCoord = nullptr;
    }
    
    return vertices;
}

void PrimitiveDisplayer::drawableWithGLRotation(Drawable* tetromino) {
    drawableWithGLRotation(tetromino, tetromino->getRotation());
}

void PrimitiveDisplayer::drawableWithGLRotation(Drawable* drawable, float rotation, Vec2d* coords) {
    Vec2d* pivotPoint = drawable->getPivotPoint()->getScale(pixelsPerSquare);
    
    glPushMatrix();
    // move to object coords - invert the y coordinate
    glTranslatef(coords->getX() * pixelsPerSquare, (20 - coords->getY()) * pixelsPerSquare, 0.f);
    
    // perform the rotation by moving to the pivot point (again inverting y), rotating, then moving back.
    glTranslatef(pivotPoint->getX(), -pivotPoint->getY(), 0.f);
    glRotatef(rotation, 0.f, 0.f, 1.f);
    glTranslatef(-pivotPoint->getX(), pivotPoint->getY(), 0.f);
    
    // draw the quads with no rotation
    for (auto quad : *drawable->getQuads()) {
        drawQuad(quad);
    }
    glPopMatrix();
    
    delete pivotPoint;
    pivotPoint = nullptr;
    coords = nullptr;
}

void PrimitiveDisplayer::drawableWithGLRotation(Drawable* drawable, float rotation) {
    drawableWithGLRotation(drawable, rotation, drawable->getCoords());
}

void PrimitiveDisplayer::drawableWithManualRotation(Drawable* drawable) {
    Vec2d* coords = drawable->getCoords();
    float rot = drawable->getRotation() * M_PI / 180;
    
    glPushMatrix();
        glTranslatef((coords->getX() + 1) * pixelsPerSquare, (21 - coords->getY()) * pixelsPerSquare, 0.f);
        for (auto quad : *drawable->getQuads()) {
            drawQuad(quad, drawable->getPivotPoint(), rot);
        }
    glPopMatrix();
    coords = nullptr;
}

void PrimitiveDisplayer::drawQuad(Quad* quad) {
    glPushMatrix();
        glShadeModel(GL_FLAT);
        float* vertices = quad->toVerticesWithInvertedY(pixelsPerSquare);
        
        glColor3fv(quad->getFillColour()->getColour3fv());
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        
        glColor3fv(quad->getLineColour()->getColour3fv());
        glLineWidth(2);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
        
        glDisableClientState(GL_VERTEX_ARRAY);
        delete[] vertices;
        vertices = nullptr;
    glPopMatrix();
}

void PrimitiveDisplayer::drawQuad(Quad* quad, Vec2d* pivotPoint, float pivotAngle) {
    glPushMatrix();
        glShadeModel(GL_FLAT);
        float* vertices = quad->toRotatedVerticesWithInvertedY(pixelsPerSquare, pivotPoint, pivotAngle);
    
        glColor3fv(quad->getFillColour()->getColour3fv());
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);

        glColor3fv(quad->getLineColour()->getColour3fv());
        glLineWidth(2);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
        
        glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void PrimitiveDisplayer::drawSquare(Vec2d* coords, GLfloat blockSize, Colour* colour, Colour* outlineColour, bool outline, Vec2d* rotationPoint, float rotation) {
    glPushMatrix();
        glTranslatef(coords->getX(), coords->getY(), 0.f);
    
        glColor3fv(colour->getColour3fv());
        
        glShadeModel(GL_FLAT);
        
        GLfloat* vertices = getRotatedVertices(blockSize, rotation);
    
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        
        glColor3fv(colour->getColour3fv());
        glDrawArrays(GL_QUADS, 0, 4);
        if (outline) {
            glColor3fv(outlineColour->getColour3fv());
            glLineWidth(2);
            glDrawArrays(GL_LINE_LOOP, 0, 4);
        }
        glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void PrimitiveDisplayer::drawSquare(Vec2d* coords, GLfloat blockSize, Colour* colour, Colour* outlineColour, bool outline) {
    drawSquare(coords, blockSize, colour, outlineColour, outline, Vec2d::ORIGIN, 0);
}

GLfloat* PrimitiveDisplayer::vectorToArray(vector<Vec2d*>* vecs) {
    int i = 0;
    GLfloat* vertices = new GLfloat[8];
    for (auto vec : *vecs) {
        vertices[i++] = vec->getX();
        vertices[i++] = vec->getY();
    }
    return vertices;
}

void PrimitiveDisplayer::drawRectangleOutline(GLfloat pixelSize, GLfloat width, GLfloat height, Colour* colour) {
    glShadeModel(GL_FLAT);
    glColor3fv(colour->getColour3fv());
    GLfloat vertices[8] = {
        0                   ,0
        ,pixelSize * width  ,0
        ,pixelSize * width  ,pixelSize * height
        ,0                  ,pixelSize * height
    };
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vertices);
    glLineWidth(4);
	glDrawArrays(GL_LINE_LOOP, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/*
 * Assumed to delete the supplied coordinates
 */
void PrimitiveDisplayer::drawRectangleOutline(Vec2d origin, Vec2d dimensions, Colour* colour) {
    glPushMatrix();
        glTranslatef(origin.getX(), origin.getY(), 0.f);
    
        glColor3fv(colour->getColour3fv());
    
        glShadeModel(GL_FLAT);
        GLfloat vertices[8] = {
             0                  ,0
            ,dimensions.getX()  ,0
            ,dimensions.getX()  ,dimensions.getY()
            ,0                  ,dimensions.getY()
        };
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glLineWidth(4);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void translate(Vec2d* coords) {
    translate(coords);
}

void translate(Vec2d* coords, GLfloat pixelSize) {
    glTranslatef(coords->getX() * pixelSize, coords->getY() * pixelSize, 0);
}
