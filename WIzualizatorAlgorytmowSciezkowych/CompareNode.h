#pragma once
#include "Node.h"

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const;
};


