
#ifndef __lanaTetris__Translation__
#define __lanaTetris__Translation__

#include "Transformation.h"
#include "TransformationData.h"

class Translation: public Transformation {
private:
    Vec2d* direction;
public:
    Translation(Vec2d*);
    ~Translation();
    TransformationType getTransformationType();
    vector<Quad*>* transform(vector<Quad*>*);
    void transform(TransformationData&);
    Vec2d* getTranslationVector();
};

#endif /* defined(__lanaTetris__Translation__) */
