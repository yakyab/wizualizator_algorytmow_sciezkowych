#include "Dijkstra.h"
#include "Grid.h"
#include "Node.h"
#include "CompareNode.h"
#include <queue>

// Implementacja algorytmu Dijkstry do znajdowania najkr�tszej �cie�ki w siatce
void Dijkstra(Grid& grid, const Point& start, const Point& end) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openList;

    Node& startNode = grid.getNode(start.x, start.y);
    Node& endNode = grid.getNode(end.x, end.y);

    // Inicjalizacja w�z�a pocz�tkowego
    startNode.cost = 0;
    startNode.status = Node::Status::OPEN;
    openList.push(&startNode);

    // G��wna p�tla algorytmu
    while (!openList.empty()) {
        Node* currentNode = openList.top();
        openList.pop();

        currentNode->status = Node::Status::CLOSED;

        // Je�li dotarli�my do w�z�a ko�cowego, zako�cz algorytm
        if (currentNode->position == endNode.position) {
            Node* pathNode = currentNode;
            while (pathNode->parent) {
                pathNode = pathNode->parent;
                pathNode->status = Node::Status::PATH;
            }
            return;
        }

        // Przetwarzanie s�siaduj�cych w�z��w
        std::vector<Point> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        for (const auto& dir : directions) {
            int newX = currentNode->position.x + dir.x;
            int newY = currentNode->position.y + dir.y;
            if (newX >= 0 && newX < grid.getWidth() && newY >= 0 && newY < grid.getHeight()) {
                Node& neighbor = grid.getNode(newX, newY);
                if (neighbor.status != Node::Status::OBSTACLE && neighbor.status != Node::Status::CLOSED) {
                    float newCost = currentNode->cost + 1; // Zak�adamy r�wny koszt dla ka�dego kroku
                    if (newCost < neighbor.cost || neighbor.status == Node::Status::UNVISITED) {
                        neighbor.cost = newCost;
                        neighbor.parent = currentNode;
                        if (neighbor.status != Node::Status::OPEN) {
                            openList.push(&neighbor);
                            neighbor.status = Node::Status::OPEN;
                        }
                    }
                }
            }
        }
    }
}






