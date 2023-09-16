#include "CompareNode.h"
#include "Node.h"

// Operator por�wnania dla w�z��w, u�ywany w kolejce priorytetowej
// W�z�y s� por�wnywane na podstawie ich ca�kowitego kosztu
bool CompareNode::operator()(const Node* a, const Node* b) const {
    return a->getTotalCost() > b->getTotalCost();
}


