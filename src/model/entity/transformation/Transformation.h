
#ifndef __lanaTetris__Transformation__
#define __lanaTetris__Transformation__

#include <vector>
#include "TransformationType.h"
#include "TransformationData.h"
#include "../tetris/Quad.h"


class Transformation {
private:
public:
    virtual ~Transformation() {};
    virtual TransformationType getTransformationType() = 0;
    virtual void transform(TransformationData&) = 0;
    virtual vector<Quad*>* transform(vector<Quad*>*) = 0;
};

#endif /* defined(__lanaTetris__Transformation__) */
