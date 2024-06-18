#include "utils.h"
#include <cmath>
#include <stdexcept>

float clipAngle(float theta) {
    const float TWO_PI = 2.0f * M_PI;
    while (theta < 0.0f) {
        theta += TWO_PI;
    }
    while (theta >= TWO_PI) {
        theta -= TWO_PI;
    }
    return theta;
}

Eigen::VectorXf SE2ToVec(const Eigen::MatrixXf& SE2) {
    if (SE2.rows() != 3 || SE2.cols() != 3) {
        throw std::runtime_error("The input matrix must be 3x3.");
    }

    Eigen::VectorXf vec(3);
    float theta = std::atan2(SE2(1, 0), SE2(0, 0));
    vec(0) = clipAngle(theta);
    vec(1) = SE2(0, 2);
    vec(2) = SE2(1, 2);

    return vec;
}

Eigen::MatrixX<Float> vecToSE2(Eigen::VectorX<Float> vec) {
    if (vec.size() != 3)
        throw std::runtime_error("vector must be 3x1.");

    Eigen::MatrixX<Float> ret;
    ret.resize(3, 3);
    ret.setIdentity();

    Float theta = vec[2];
    ret(0, 0) = std::cos(theta);
    ret(0, 1) = -std::sin(theta);
    ret(1, 0) = std::sin(theta);
    ret(1, 1) = std::cos(theta);

    ret(0, 2) = vec[0];
    ret(1, 2) = vec[1];
    return ret;
}

Eigen::MatrixX<Float> vecToSO2(Eigen::VectorX<Float> vec) {
    if (vec.size() != 3)
        throw std::runtime_error("vector must be 3x1.");

    Eigen::MatrixX<Float> ret(2, 2);

    Float theta = vec[2];
    ret(0, 0) = std::cos(theta);
    ret(0, 1) = -std::sin(theta);
    ret(1, 0) = std::sin(theta);
    ret(1, 1) = std::cos(theta);

    return ret;
}
