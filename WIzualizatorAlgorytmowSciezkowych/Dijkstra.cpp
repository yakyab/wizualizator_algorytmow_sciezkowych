#include <queue>
#include "Grid.h"
#include "Node.h"
#include "CompareNode.h"


void Dijkstra(Grid& grid, const Point& start, const Point& end) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openList;


    Node& startNode = grid.getNode(start.x, start.y);
    startNode.cost = 0;
    openList.push(&startNode);

    while (!openList.empty()) {
        Node* currentNode = openList.top();
        openList.pop();

        if (currentNode->position == end) {
            return;
        }

        // Process neighbors
        std::vector<Point> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        for (const auto& dir : directions) {
            int newX = currentNode->position.x + dir.x;
            int newY = currentNode->position.y + dir.y;
            if (newX >= 0 && newX < grid.getWidth() && newY >= 0 && newY < grid.getHeight()) {
                Node& neighbor = grid.getNode(newX, newY);
                if (neighbor.status != Node::Status::OBSTACLE && neighbor.status != Node::Status::CLOSED) {
                    float newCost = currentNode->cost + 1; // Assuming equal cost for each step
                    if (newCost < neighbor.cost) {
                        neighbor.cost = newCost;
                        neighbor.parent = currentNode;
                        openList.push(&neighbor);
                    }
                }
            }
        }

        currentNode->status = Node::Status::CLOSED;
    }
}

