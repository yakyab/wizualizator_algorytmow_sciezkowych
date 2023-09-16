#include "Grid.h"
#include "Point.h"
#include <iostream>

void retracePath(Grid& grid, const Point& start, const Point& end) {
    Point current = end;
    while (current != start) {
        Node& currentNode = grid.getNode(current.x, current.y);
        if (currentNode.parent == nullptr) {
            // Je�li w�ze� nie ma rodzica, co� posz�o nie tak
            std::cerr << "B��d podczas wyznaczania �cie�ki: w�ze� nie ma rodzica.\n";
            return;
        }
        currentNode.status = Node::Status::PATH;
        current = currentNode.parent->position;
    }
}

