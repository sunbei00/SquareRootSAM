#ifndef SQUAREROOTSAM_CPP_UTILS_H
#define SQUAREROOTSAM_CPP_UTILS_H

#include <Eigen/Core>
#include <Eigen/Dense>

using Float = float;
using Int = int;
using uInt = uint32_t;

float clipAngle(float theta);
Eigen::VectorXf SE2ToVec(const Eigen::MatrixXf& SE2);
Eigen::MatrixX<Float> vecToSE2(Eigen::VectorX<Float> vec);
Eigen::MatrixX<Float> vecToSO2(Eigen::VectorX<Float> vec);

#endif // SQUAREROOTSAM_CPP_UTILS_H
