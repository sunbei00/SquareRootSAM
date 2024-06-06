//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_FACTOR2D_H
#define SQUAREROOTSAM_CPP_FACTOR2D_H
#include <FactorBase.h>

class FactorRelativeError2D : public FactorBase{
public:
    FactorRelativeError2D(uInt fromNode, uInt toNode);
    ~FactorRelativeError2D() override;
    uInt getDimension() override;
    Eigen::VectorX<Float> getResidual() override;
    Eigen::MatrixX<Float> getJacobian() override;

private:
    static constexpr uInt dim = 3;
    Eigen::Matrix<Float,1,dim> measurement;
};


#endif //SQUAREROOTSAM_CPP_FACTOR2D_H
