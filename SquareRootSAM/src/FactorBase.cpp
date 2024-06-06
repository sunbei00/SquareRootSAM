//
// Created by KwonSungMin on 2024-06-06.
//

#include "FactorBase.h"


void FactorBase::setId(uInt id){
    this->id = id;
}
uInt FactorBase::getId(){
    return id;
}

uInt FactorBase::nextId = 0;
uInt FactorBase::getNextId(){
    uInt ret = FactorBase::nextId;
    FactorBase::nextId++;
    return ret;
}

FactorBase::FactorBase(uInt fromNode, uInt toNode) : fromNode(fromNode), toNode(toNode), id(FactorBase::getNextId()){}

FactorBase::~FactorBase() = default;





