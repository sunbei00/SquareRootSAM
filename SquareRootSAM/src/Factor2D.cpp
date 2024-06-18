//
// Created by KwonSungMin on 2024-06-06.
//

#include "Factor2D.h"

#include <utility>
#include <NodeBase.h>


Eigen::VectorX<Float> FactorRelativeError2D::getResidual(){
    auto from = NodeBase::getState(fromNode);
    auto to =  NodeBase::getState(toNode);

    auto from_SE2 = vecToSE2(from);
    auto to_SE2 = vecToSE2(to);

    auto measurement_SE2 = vecToSE2(measurement);

    return SE2ToVec(measurement_SE2.inverse() * from_SE2.inverse() * to_SE2);
}

Eigen::MatrixX<Float> FactorRelativeError2D::getJacobian(){

    Eigen::MatrixX<Float> ret(3,6);
    ret.setZero();

    // 3x1
    Eigen::VectorX<Float> from = NodeBase::getState(fromNode);
    Eigen::VectorX<Float> to =  NodeBase::getState(toNode);

    // 2x2
    Eigen::MatrixX<Float> from_SO2 = vecToSO2(from);
    Eigen::MatrixX<Float> to_SO2 = vecToSO2(to);
    Eigen::MatrixX<Float> measurement_SO2 = vecToSO2(measurement);


    // from
    ret.block<2,2>(0,0) = -measurement_SO2.transpose() * from_SO2.transpose();

    Float sinFrom = std::sin(to(2));
    Float cosFrom = std::cos(to(2));
    Eigen::MatrixX<Float> differential(2,2);
    differential << - sinFrom, -cosFrom,
                    cosFrom,   -sinFrom;

    ret.block<2,1>(2,0) = measurement_SO2.transpose() * differential.transpose() * (to.block<2,1>(0,0) - from.block<2,1>(0,0));
    ret(2,2) = -1;

    // to
    ret.block<3,3>(0,3).setIdentity();
    ret.block<2,2>(0,3) = measurement_SO2.transpose() * from_SO2.transpose();


    return ret;
}

FactorRelativeError2D::FactorRelativeError2D(uInt fromNode, uInt toNode, Eigen::MatrixX<Float> informationMatrix)
: Factor<3>(fromNode, toNode, std::move(informationMatrix)){}



FactorRelativeError2D::~FactorRelativeError2D() = default;

