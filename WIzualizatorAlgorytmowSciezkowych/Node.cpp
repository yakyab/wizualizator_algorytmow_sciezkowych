#include "Node.h"

Node::Node(int x, int y) : position(x, y), parent(nullptr), cost(0.0f), heuristic(0.0f), status(Node::Status::UNVISITED) {}

float Node::getTotalCost() const {
    return cost + heuristic;
}
