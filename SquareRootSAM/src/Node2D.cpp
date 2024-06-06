//
// Created by KwonSungMin on 2024-06-06.
//

#include "Node2D.h"

Node2D::Node2D(){

}
Node2D::Node2D(Eigen::VectorX<Float> state){
    setState(state);
}

uInt Node2D::getDimension() {
    return dim;
}

Eigen::VectorX<Float> Node2D::getState() {
    return state;
}

void Node2D::setState(Eigen::VectorX<Float> state) {
    if(dim != state.size())
        throw std::runtime_error("Node2D, setState() - mismatch dimension");
    this->state = state;
}

Node2D::~Node2D() = default;