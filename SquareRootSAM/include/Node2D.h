//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_NODE2D_H
#define SQUAREROOTSAM_CPP_NODE2D_H
#include <NodeBase.h>

class Node2D : public NodeBase{
public:
    ~Node2D() override;
    Node2D();
    Node2D(Eigen::VectorX<Float>);
    uInt getDimension() override;
    Eigen::VectorX<Float> getState() override;
    void setState(Eigen::VectorX<Float>) override;

private:
    static constexpr uInt dim = 3;
    Eigen::Matrix<Float,1,dim> state;
};


#endif //SQUAREROOTSAM_CPP_NODE2D_H
