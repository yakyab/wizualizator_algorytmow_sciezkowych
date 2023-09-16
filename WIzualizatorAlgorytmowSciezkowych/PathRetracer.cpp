#include "Grid.h"
#include "Point.h"
#include <iostream>

// Funkcja œledz¹ca œcie¿kê od punktu koñcowego do punktu pocz¹tkowego
void retracePath(Grid& grid, const Point& start, const Point& end) {
    Point current = end;
    while (current != start) {
        Node& currentNode = grid.getNode(current.x, current.y);
        currentNode.status = Node::Status::PATH;
        current = currentNode.parent->position;
    }
}


