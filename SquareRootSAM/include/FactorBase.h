//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_FACTORBASE_H
#define SQUAREROOTSAM_CPP_FACTORBASE_H
#include <Utils.h>

class FactorBase {
public:
    FactorBase(uInt fromNode, uInt toNode);
    virtual ~FactorBase();
    virtual uInt getDimension() = 0;
    virtual Eigen::VectorX<Float> getResidual() = 0;
    virtual Eigen::MatrixX<Float> getJacobian() = 0;

    uInt getId();


protected:
    void setId(uInt id);
    static uInt getNextId();
    uInt id;
    uInt fromNode;
    uInt toNode;

    static uInt nextId;
};




#endif //SQUAREROOTSAM_CPP_FACTORBASE_H
