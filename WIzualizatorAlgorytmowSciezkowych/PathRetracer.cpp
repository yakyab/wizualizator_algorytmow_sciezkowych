#include "Grid.h"
#include "Point.h"
#include <iostream>

// Funkcja �ledz�ca �cie�k� od punktu ko�cowego do punktu pocz�tkowego
void retracePath(Grid& grid, const Point& start, const Point& end) {
    Point current = end;
    while (current != start) {
        Node& currentNode = grid.getNode(current.x, current.y);
        currentNode.status = Node::Status::PATH;
        current = currentNode.parent->position;
    }
}


