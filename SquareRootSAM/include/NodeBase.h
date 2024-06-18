//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_NODEBASE_H
#define SQUAREROOTSAM_CPP_NODEBASE_H
#include <Utils.h>

class NodeBase {
public:
    NodeBase();
    virtual ~NodeBase();
    virtual Eigen::VectorX<Float> getState() = 0;
    virtual void setState(Eigen::VectorX<Float>) = 0;
    virtual uInt getDimension() = 0;
    uInt getId();
    static Eigen::VectorX<Float> getState(uInt id);


protected:
    uInt id;
    static std::unordered_map<uInt, NodeBase*> idMapping;
private:
    static void setNextId(NodeBase*);
    static uInt nextId;
};


template <int dim>
class Node : public NodeBase{
public:
    Node(Eigen::Matrix<Float,1,dim> state);
    uInt getDimension() override;
    void setState(Eigen::VectorX<Float>) override;
    Eigen::VectorX<Float> getState() override;

protected:
    Eigen::Matrix<Float,dim,1> state;
};

template<int dim>
Node<dim>::Node(Eigen::Matrix<Float,1,dim> state) {
    setState(state);
}

template<int dim>
Eigen::VectorX<Float> Node<dim>::getState() {
    return state;
}

template<int dim>
void Node<dim>::setState(Eigen::VectorX<Float>) {
    if(dim != state.size())
        throw std::runtime_error("Node2D, setState() - mismatch dimension");
    this->state = state;
}

template<int dim>
uInt Node<dim>::getDimension() {
    return dim;
}


#endif //SQUAREROOTSAM_CPP_NODEBASE_H
