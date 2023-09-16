#pragma once
#include "Node.h"

// Struktura porównuj¹ca wêz³y na podstawie ich ca³kowitego kosztu
struct CompareNode {
    bool operator()(const Node* a, const Node* b) const;
};



