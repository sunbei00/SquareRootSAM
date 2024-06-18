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

void Graph::optimize() {

    if(nodes.size() <= 0)
        return;

    uInt rows = 0;
    uInt cols = 0;

    for(auto& it : factors)
        rows += it->getDimension();
    for(auto& it : nodes)
        cols += it->getDimension();

    int priorDim = nodes[0]->getDimension();
    Eigen::MatrixX<Float> A(rows + priorDim ,cols);
    A.setZero();

    // piror
    A.block(0,0, priorDim, priorDim).setIdentity();

    Eigen::VectorX<Float> b(rows + priorDim);
    b.setZero();

    uInt startDim = priorDim;
    for(auto& it : factors) {
        // Information Square root 해서 곱해줘야됨. -> 아직 구현 안함.
        Eigen::MatrixX<Float> A_factor = it->getJacobian();
        Eigen::VectorX<Float> b_factor = - it->getResidual();

        b.block(startDim,0,it->getDimension(),1) = b_factor;
        startDim += it->getDimension();


        uInt fromIdx = it->getFromNode();
        uInt toIdx = it->getToNode();
        uInt rowIdx = it->getId();

        // assume only 2D Relative Pose Error
        A.block(3*(rowIdx+1),3*(fromIdx),3,3) = A_factor.block<3,3>(0,0);
        A.block(3*(rowIdx+1),3*(toIdx),3,3) = A_factor.block<3,3>(0,3);
    }


    Eigen::VectorX<Float> delta = A.colPivHouseholderQr().solve(b);

    startDim = 0;
    for (size_t i = 0; i < nodes.size(); ++i) {
        nodes[i]->setState(nodes[i]->getState() + delta.block(startDim,0,nodes[i]->getDimension(),1));
        startDim += nodes[i]->getDimension();
    }
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

