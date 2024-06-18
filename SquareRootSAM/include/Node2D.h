//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_NODE2D_H
#define SQUAREROOTSAM_CPP_NODE2D_H
#include <NodeBase.h>

class Node2D : public Node<3>{
public:
    ~Node2D() override;
    Node2D(const Eigen::VectorX<Float>&);

};



#endif //SQUAREROOTSAM_CPP_NODE2D_H
