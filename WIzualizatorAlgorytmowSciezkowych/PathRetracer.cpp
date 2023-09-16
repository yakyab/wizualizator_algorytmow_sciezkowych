#include "Grid.h"
#include "Point.h"
#include <iostream>

void retracePath(Grid& grid, const Point& start, const Point& end) {
    Point current = end;
    while (current != start) {
        Node& currentNode = grid.getNode(current.x, current.y);
        if (currentNode.parent == nullptr) {
            // Jeœli wêze³ nie ma rodzica, coœ posz³o nie tak
            std::cerr << "B³¹d podczas wyznaczania œcie¿ki: wêze³ nie ma rodzica.\n";
            return;
        }
        currentNode.status = Node::Status::PATH;
        current = currentNode.parent->position;
    }
}

