
#ifndef __lanaTetris__Rotation__
#define __lanaTetris__Rotation__

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Transformation.h"

class Rotation: public Transformation {
private:
    TransformationType type = TransformationType::ROTATION;
    float angleDegrees;
    float angleRadians;
    Vec2d* pivotPoint = nullptr;
    
public:
    Rotation(Vec2d*, float);
    ~Rotation();
    
    TransformationType getTransformationType();
    vector<Quad*>* transform(vector<Quad*>*);
    void transform(TransformationData&);
};

#endif /* defined(__lanaTetris__Rotation__) */
