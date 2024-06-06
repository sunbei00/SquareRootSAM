//
// Created by KwonSungMin on 2024-06-06.
//

#include "Factor2D.h"



uInt FactorRelativeError2D::getDimension(){
    return dim;
}
Eigen::VectorX<Float> FactorRelativeError2D::getResidual(){

}
Eigen::MatrixX<Float> FactorRelativeError2D::getJacobian(){

}

FactorRelativeError2D::FactorRelativeError2D(uInt fromNode, uInt toNode) : FactorBase(fromNode, toNode){}

FactorRelativeError2D::~FactorRelativeError2D() = default;

