
#ifndef __lanaTetris__TransformationData__
#define __lanaTetris__TransformationData__

#include <vector>
#include "../tetris/Quad.h"

class TransformationData {
private:
    vector<Quad*>* previousQuads;
    float previousRotation;
    Vec2d* previousOffset;
    
    vector<Quad*>* workingQuads;
    float workingRotation;
    Vec2d* workingOffset;
    
    bool twoState = false;
public:
    TransformationData(vector<Quad*>*, Vec2d*, bool);
    ~TransformationData();

    vector<Quad*>* getPreviousQuads();
    float getPreviousRotation();
    Vec2d* getPreviousOffset();
    
    vector<Quad*>* getWorkingQuads();
    float getWorkingRotation();
    Vec2d* getWorkingOffset();
    
    void setPreviousQuads(vector<Quad*>*);
    void setPreviousRotation(float);
    void setPreviousOffset(Vec2d*);
    
    void setWorkingQuads(vector<Quad*>*);
    void setWorkingRotation(float);
    void setWorkingOffset(Vec2d*);

    TransformationData* withPreviousQuads(vector<Quad*>*);
    TransformationData* withPreviousRotation(float);
    TransformationData* withPreviousOffset(Vec2d*);
    
    TransformationData* withWorkingQuads(vector<Quad*>*);
    TransformationData* withWorkingRotation(float);
    TransformationData* withWorkingOffset(Vec2d*);
    
    void rollforward();
    void rollback();
    
    bool isTwoState();
};

#endif /* defined(__lanaTetris__TransformationData__) */
