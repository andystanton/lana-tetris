
#ifndef __lanaTetris__PrimitiveDisplayer__
#define __lanaTetris__PrimitiveDisplayer__

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "GLFW/glfw3.h"
#include "../model/foundation/Vec2d.h"
#include "../model/entity/tetris/Quad.h"
#include "../model/entity/Drawable.h"
#include "../drawing/foundation/Colour.h"
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

class PrimitiveDisplayer {
private:
    PrimitiveDisplayer(GLfloat pixelsPerSquare);
    
    static PrimitiveDisplayer* primitiveDisplayer;
    
    GLfloat pixelsPerSquare = 20;
    Vec2d** verticesVec;

public:
    static PrimitiveDisplayer* getInstance();
    
    GLfloat getPixelsPerSquare();
    GLfloat* getRotatedVertices(GLfloat blockSize, float angle);
    GLfloat* vectorToArray(vector<Vec2d*>* vec);
    
    void drawableWithGLRotation(Drawable*);
    void drawableWithGLRotation(Drawable*, float);
    void drawableWithGLRotation(Drawable*, float, Vec2d*);
    void drawableWithManualRotation(Drawable*);
    void drawQuad(Quad*);
    void drawQuad(Quad*, Vec2d*, float);
    
    void drawSquare();
    void drawSquare(GLfloat pixelSize);
    void drawSquare(Vec2d* coords, GLfloat blockSize, Colour* colour, Colour* outlineColour, bool outline);
    void drawSquare(Vec2d* coords, GLfloat blockSize, Colour* colour, Colour* outlineColour, bool outline, Vec2d* rotationPoint, float rotation);

    void drawRectangleOutline(GLfloat pixelSize, GLfloat width, GLfloat height, Colour* colour);
    void drawRectangleOutline(Vec2d origin, Vec2d dimensions, Colour* colour);

    void translate(Vec2d*);
    void translate(Vec2d*, GLfloat pixelSize);
};

#endif /* defined(__lanaTetris__PrimitiveDisplayer__) */
