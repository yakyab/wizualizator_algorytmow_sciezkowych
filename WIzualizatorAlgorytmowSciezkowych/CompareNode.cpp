#include "CompareNode.h"
#include "Node.h"

bool CompareNode::operator()(const Node* a, const Node* b) const {
    return a->cost > b->cost;
}
