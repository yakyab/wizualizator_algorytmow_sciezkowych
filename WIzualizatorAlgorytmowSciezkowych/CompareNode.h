#pragma once
#include "Node.h"

// Struktura por�wnuj�ca w�z�y na podstawie ich ca�kowitego kosztu
struct CompareNode {
    bool operator()(const Node* a, const Node* b) const;
};



