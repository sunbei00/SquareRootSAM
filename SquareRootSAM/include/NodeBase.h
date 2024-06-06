//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_NODEBASE_H
#define SQUAREROOTSAM_CPP_NODEBASE_H
#include <Utils.h>

class NodeBase {
public:
    NodeBase();
    virtual ~NodeBase();
    virtual uInt getDimension() = 0;
    virtual Eigen::VectorX<Float> getState() = 0;
    virtual void setState(Eigen::VectorX<Float>) = 0;
    uInt getId();


protected:
    static uInt getNextId();
    void setId(uInt id);
    uInt id;
private:
    static uInt nextId;
};





#endif //SQUAREROOTSAM_CPP_NODEBASE_H
