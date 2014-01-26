
#ifndef __lanaTetris__Pipeline__
#define __lanaTetris__Pipeline__

#include <vector>
#include "Transformation.h"
#include "Translation.h"
#include "PipelineResult.h"
#include "../collision/Collidable.h"
#include "../tetris/Tetromino.h"

class Pipeline {
private:
    Tetromino* transformee;
    vector<Transformation*>* pipeline;
    vector<Collidable*>* collidables;
public:
    Pipeline(Tetromino*);
    ~Pipeline();

    void addTransformation(Transformation*);
    void addTransformations(vector<Transformation*>*);
    void addCollidable(Collidable*);
    
    PipelineResult* execute();
    
    Collidable::CollisionType hitCollidable(TransformationData&, Transformation*);
};

#endif /* defined(__lanaTetris__Pipeline__) */
