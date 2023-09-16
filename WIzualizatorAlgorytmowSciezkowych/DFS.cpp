#include "DFS.h"
#include "Grid.h"
#include "Node.h"
#include <stack>

// Implementacja algorytmu DFS do przeszukiwania siatki
void DFS(Grid& grid, const Point& start, const Point& end) {
    std::stack<Node*> stack;

    Node& startNode = grid.getNode(start.x, start.y);
    startNode.status = Node::Status::OPEN;
    stack.push(&startNode);

    // G³ówna pêtla algorytmu
    while (!stack.empty()) {
        Node* currentNode = stack.top();
        stack.pop();

        // Jeœli dotarliœmy do wêz³a koñcowego, zakoñcz algorytm
        if (currentNode->position == end) {
            return;
        }

        // Przetwarzanie s¹siaduj¹cych wêz³ów
        std::vector<Point> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        for (const auto& dir : directions) {
            int newX = currentNode->position.x + dir.x;
            int newY = currentNode->position.y + dir.y;
            if (newX >= 0 && newX < grid.getWidth() && newY >= 0 && newY < grid.getHeight()) {
                Node& neighbor = grid.getNode(newX, newY);
                if (neighbor.status == Node::Status::UNVISITED) {
                    neighbor.parent = currentNode;
                    stack.push(&neighbor);
                    neighbor.status = Node::Status::OPEN;
                }
            }
        }

        currentNode->status = Node::Status::CLOSED;
    }
}




