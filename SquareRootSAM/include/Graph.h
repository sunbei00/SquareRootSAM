//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_GRAPH_H
#define SQUAREROOTSAM_CPP_GRAPH_H
#include <FactorBase.h>
#include <NodeBase.h>
#include <vector>

class Graph {
public:
    void addNode(NodeBase* node);
    void addFactor(FactorBase* factor);

    ~Graph();

protected:
    std::vector<NodeBase*> nodes;
    std::vector<FactorBase*> factors;
};


#endif //SQUAREROOTSAM_CPP_GRAPH_H
