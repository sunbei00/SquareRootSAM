//
// Created by KwonSungMin on 2024-06-06.
//

#include "FactorBase.h"



uInt FactorBase::getId(){
    return id;
}

uInt FactorBase::nextId = 0;
void FactorBase::setNextId(FactorBase* factor){
    factor->id = FactorBase::nextId;
    idMapping.insert({factor->id,factor});
    FactorBase::nextId++;
}

FactorBase::FactorBase(uInt fromNode, uInt toNode)
: fromNode(fromNode), toNode(toNode) {
    setNextId(this);
}

uInt FactorBase::getFromNode() {
    return fromNode;
}

uInt FactorBase::getToNode() {
    return toNode;
}

std::unordered_map<uInt, FactorBase*> FactorBase::idMapping;

FactorBase::~FactorBase() = default;







