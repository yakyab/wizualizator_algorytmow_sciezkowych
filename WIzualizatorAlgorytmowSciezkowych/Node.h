#pragma once
#include "Point.h"

class Node {
public:
    Point position;
    Node* parent;
    float cost; // Koszt dojœcia do tego wêz³a
    float heuristic; // Heurystyka (dla algorytmu A*)

    enum class Status {
        UNVISITED,
        OPEN,
        CLOSED,
        START,
        END,
        OBSTACLE
    };

    Status status;

    Node();
    Node(int x, int y);

    float getTotalCost() const { return cost + heuristic; }
    bool operator==(const Node& other) const { return position == other.position; }

    struct CompareNode {
        bool operator()(const Node* a, const Node* b) const {
            return a->cost > b->cost;
        }
    };
};



