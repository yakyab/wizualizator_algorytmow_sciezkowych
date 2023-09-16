#include "CompareNode.h"
#include "Node.h"

bool CompareNode::operator()(const Node* a, const Node* b) const {
    return a->getTotalCost() > b->getTotalCost();
}

