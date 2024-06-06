//
// Created by KwonSungMin on 2024-06-06.
//

#include "Graph.h"


void Graph::addNode(NodeBase* node){
    nodes.push_back(node);
}

void Graph::addFactor(FactorBase* factor){
    factors.push_back(factor);
}
/**/

Graph::~Graph() {
    for(auto& node : nodes)
        delete node;
    for(auto& factor : factors)
        delete factor;
}


/*
 *
 * Node 지울 때, node id에 대해서 어떻게 처리할지 고민 필요. 현재 node id를 static으로 선언해서 하나씩 주는 방식임.
 *  이유 -> id 기반으로 index를 써서 행렬을 구성할 것 같음.
 * Factor는 그냥 지워도 됨.
 *
 */

//void Graph::delFactor(uInt id){
//    if(factors.size() == 0 || factors.size() < id)
//        return;
//    FactorBase* delFactor = factors[id];
//    factors[id] = factors[factors.size() - 1];
//    factors.pop_back();
//    delete delFactor;
//}

