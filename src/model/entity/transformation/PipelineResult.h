
#ifndef __lanaTetris__PipelineResult__
#define __lanaTetris__PipelineResult__

#include <vector>
#include "../collision/Collidable.h"
#include "../tetris/Quad.h"
#include "../transformation/TransformationData.h"


#endif /* defined(__lanaTetris__PipelineResult__) */

class PipelineResult {
public:
    PipelineResult(vector<Quad*>*, bool, float, Vec2d*);
    PipelineResult(TransformationData&, bool);
    ~PipelineResult();

    bool isDead();
    float getNetRotation();
    Vec2d* getNetOffset();
    vector<Quad*>* getQuads();
private:
    bool dead;
    float netRotation;
    Vec2d* netOffset;
    vector<Quad*>* quads;
};