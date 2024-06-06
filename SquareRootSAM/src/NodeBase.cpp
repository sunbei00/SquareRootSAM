//
// Created by KwonSungMin on 2024-06-06.
//

#include "NodeBase.h"


void NodeBase::setId(uInt id){
    this->id = id;
}
uInt NodeBase::getId(){
    return id;
}

uInt NodeBase::nextId = 0;
uInt NodeBase::getNextId(){
    uInt ret = NodeBase::nextId;
    NodeBase::nextId++;
    return ret;
}

NodeBase::NodeBase() : id(NodeBase::getNextId()){}
NodeBase::~NodeBase() = default;



