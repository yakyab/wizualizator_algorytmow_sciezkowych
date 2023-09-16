#include "Node.h"

// Domy�lny konstruktor klasy Node
Node::Node() : position(0, 0), parent(nullptr), cost(0.0f), heuristic(0.0f), status(Node::Status::UNVISITED) {}

// Konstruktor klasy Node z okre�lonymi wsp�rz�dnymi
Node::Node(int x, int y) : position(x, y), parent(nullptr), cost(0.0f), heuristic(0.0f), status(Node::Status::UNVISITED) {}




