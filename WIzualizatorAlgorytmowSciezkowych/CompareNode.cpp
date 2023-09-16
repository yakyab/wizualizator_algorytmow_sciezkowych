#include "CompareNode.h"
#include "Node.h"

// Operator porównania dla wêz³ów, u¿ywany w kolejce priorytetowej
// Wêz³y s¹ porównywane na podstawie ich ca³kowitego kosztu
bool CompareNode::operator()(const Node* a, const Node* b) const {
    return a->getTotalCost() > b->getTotalCost();
}


