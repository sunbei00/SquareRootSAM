//
// Created by KwonSungMin on 2024-06-06.
//

#include "NodeBase.h"


uInt NodeBase::getId(){
    return id;
}

uInt NodeBase::nextId = 0;


void NodeBase::setNextId(NodeBase* node){
    node->id = NodeBase::nextId;
    idMapping.insert({node->id, node});
    NodeBase::nextId++;
}

NodeBase::NodeBase() {
    setNextId(this);
}

Eigen::VectorX<Float> NodeBase::getState(uInt id) {
    return idMapping[id]->getState();
}

std::unordered_map<uInt, NodeBase*> NodeBase::idMapping;
NodeBase::~NodeBase() = default;



