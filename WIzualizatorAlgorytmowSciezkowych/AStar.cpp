#include <queue>
#include <cmath>
#include "Grid.h"
#include "Node.h"

struct CompareNode {
    bool operator()(Node* a, Node* b) const {
        return a->getTotalCost() > b->getTotalCost();
    }
};

float heuristic(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

void AStar(Grid& grid, const Point& start, const Point& end) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openList;

    Node& startNode = grid.getNode(start.x, start.y);
    Node& endNode = grid.getNode(end.x, end.y);

    startNode.cost = 0;
    startNode.heuristic = heuristic(start, end);
    openList.push(&startNode);

    while (!openList.empty()) {
        Node* currentNode = openList.top();
        openList.pop();

        if (*currentNode == endNode) {
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
                        neighbor.heuristic = heuristic(neighbor.position, end);
                        neighbor.parent = currentNode;
                        openList.push(&neighbor);
                    }
                }
            }
        }

        currentNode->status = Node::Status::CLOSED;
    }
}

