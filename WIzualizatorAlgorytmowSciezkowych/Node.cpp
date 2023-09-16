#include "Node.h"

Node::Node() : position(0, 0), parent(nullptr), cost(0.0f), heuristic(0.0f), status(Node::Status::UNVISITED) {}


