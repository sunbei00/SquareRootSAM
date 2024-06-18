//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_FACTOR2D_H
#define SQUAREROOTSAM_CPP_FACTOR2D_H
#include <FactorBase.h>

class FactorRelativeError2D : public Factor<3>{
public:
    FactorRelativeError2D(uInt fromNode, uInt toNode, Eigen::MatrixX<Float> informationMatrix);
    ~FactorRelativeError2D() override;
    Eigen::VectorX<Float> getResidual() override;
    Eigen::MatrixX<Float> getJacobian() override;

};


#endif //SQUAREROOTSAM_CPP_FACTOR2D_H
