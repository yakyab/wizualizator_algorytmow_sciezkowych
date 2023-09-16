#include "AStar.h"
#include "Grid.h"
#include "Node.h"
#include "CompareNode.h"
#include <queue>
#include <cmath>

// Funkcja heurystyczna obliczaj¹ca przybli¿ony koszt od punktu a do punktu b
float heuristic(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// Implementacja algorytmu A* do znajdowania najkrótszej œcie¿ki w siatce
void AStar(Grid& grid, const Point& start, const Point& end) {
    // Priorytetowa kolejka wêz³ów do przetworzenia
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openList;

    Node& startNode = grid.getNode(start.x, start.y);
    Node& endNode = grid.getNode(end.x, end.y);

    // Inicjalizacja wêz³a pocz¹tkowego
    startNode.cost = 0;
    startNode.heuristic = heuristic(start, end);
    openList.push(&startNode);

    // G³ówna pêtla algorytmu
    while (!openList.empty()) {
        Node* currentNode = openList.top();
        openList.pop();

        // Jeœli dotarliœmy do wêz³a koñcowego, zakoñcz algorytm
        if (currentNode->position == end) {
            return;
        }

        currentNode->status = Node::Status::CLOSED;

        // Przetwarzanie s¹siaduj¹cych wêz³ów
        std::vector<Point> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        for (const auto& dir : directions) {
            int newX = currentNode->position.x + dir.x;
            int newY = currentNode->position.y + dir.y;
            if (newX >= 0 && newX < grid.getWidth() && newY >= 0 && newY < grid.getHeight()) {
                Node& neighbor = grid.getNode(newX, newY);
                if (neighbor.status != Node::Status::OBSTACLE && neighbor.status != Node::Status::CLOSED) {
                    float newCost = currentNode->cost + 1; // Zak³adamy równy koszt dla ka¿dego kroku
                    if (newCost < neighbor.cost || neighbor.status == Node::Status::UNVISITED) {
                        neighbor.cost = newCost;
                        neighbor.heuristic = heuristic(neighbor.position, end);
                        neighbor.parent = currentNode;
                        openList.push(&neighbor);
                        neighbor.status = Node::Status::OPEN;
                    }
                }
            }
        }
    }
}






