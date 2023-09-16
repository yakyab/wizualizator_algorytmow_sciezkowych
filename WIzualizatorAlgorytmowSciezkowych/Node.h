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
        OBSTACLE,
        PATH // Dodaj ten status
    };

    Status status;

    Node();
    Node(int x, int y);

    float getTotalCost() const { return cost + heuristic; }
    bool operator==(const Node& other) const { return position == other.position; }
};





