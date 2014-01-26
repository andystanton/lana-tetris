
#ifndef __lanaTetris__Quad__
#define __lanaTetris__Quad__

#include <vector>
#include "../../foundation/Vec2d.h"
#include "../../../drawing/foundation/Colour.h"

class Quad {
private:
    int vertexCount = 0;
    
    Vec2d** vertices = nullptr;
    Colour* fillColour = nullptr;
    Colour* lineColour = nullptr;
    
public:
    Quad();
    Quad(Quad*);
    Quad(Quad*, Vec2d*);
    ~Quad();

    int getVertexCount();
    Colour* getFillColour();
    Colour* getLineColour();
    
    Quad* withVertex(Vec2d*);
    Quad* withFillColour(Colour*);
    Quad* withLineColour(Colour*);
    
    Vec2d** getVertices();
    
    string* toString();

    float* toVertices(float);
    float* toVerticesWithInvertedY(float scale);
    float* toRotatedVertices(float, Vec2d*, float);
    float* toRotatedVerticesWithInvertedY(float, Vec2d*, float);
    
    Quad* getRotatedQuad(Vec2d*, float);
    Vec2d** getExtremities();

    bool collidesWithQuad(Quad*);
    bool collidesWithQuad(Quad*, Vec2d* offset);
    
    static Quad* getRegularQuad(Vec2d*, Colour*, Colour*);
    static void deleteQuads(vector<Quad*>*, bool);
    static vector<Quad*>* cloneQuads(vector<Quad*>*);
};

#endif /* defined(__lanaTetris__Quad__) */
