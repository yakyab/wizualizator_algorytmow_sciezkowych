#include "Grid.h"
#include "AStar.cpp"
#include "Dijkstra.cpp"
#include "BFS.cpp"
#include "DFS.cpp"
#include <iostream>

void displayMenu() {
    std::cout << "Wybierz algorytm:\n";
    std::cout << "1. A*\n";
    std::cout << "2. Dijkstra\n";
    std::cout << "3. BFS\n";
    std::cout << "4. DFS\n";
    std::cout << "5. Wyjście\n";
}

Point getUserPoint(const std::string& prompt) {
    Point p;
    std::cout << prompt << "\n";
    std::cout << "x: ";
    std::cin >> p.x;
    std::cout << "y: ";
    std::cin >> p.y;
    return p;
}

void setObstacles(Grid& grid) {
    int numObstacles;
    std::cout << "Ile przeszkód chcesz dodać? ";
    std::cin >> numObstacles;

    for (int i = 0; i < numObstacles; ++i) {
        Point obstacle = getUserPoint("Podaj współrzędne przeszkody:");
        grid.getNode(obstacle.x, obstacle.y).status = Node::Status::OBSTACLE;
    }
}

void displayGrid(const Grid& grid) {
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            const Node& node = grid.getNode(x, y);
            if (node.status == Node::Status::START) std::cout << "S ";
            else if (node.status == Node::Status::END) std::cout << "E ";
            else if (node.status == Node::Status::OBSTACLE) std::cout << "# ";
            else if (node.status == Node::Status::CLOSED) std::cout << ". ";
            else std::cout << "  ";
        }
        std::cout << "\n";
    }
}

int main() {
    Grid grid(20, 20); // Przykładowa siatka 20x20
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        Point start, end;
        switch (choice) {
        case 1:
            start = getUserPoint("Podaj punkt startowy:");
            end = getUserPoint("Podaj punkt końcowy:");
            setObstacles(grid);
            AStar(grid, start, end);
            displayGrid(grid);
            break;
        case 2:
            start = getUserPoint("Podaj punkt startowy:");
            end = getUserPoint("Podaj punkt końcowy:");
            setObstacles(grid);
            Dijkstra(grid, start, end);
            displayGrid(grid);
            break;
        case 3:
            start = getUserPoint("Podaj punkt startowy:");
            end = getUserPoint("Podaj punkt końcowy:");
            setObstacles(grid);
            BFS(grid, start, end);
            displayGrid(grid);
            break;
        case 4:
            start = getUserPoint("Podaj punkt startowy:");
            end = getUserPoint("Podaj punkt końcowy:");
            setObstacles(grid);
            DFS(grid, start, end);
            displayGrid(grid);
            break;
        case 5:
            std::cout << "Do widzenia!\n";
            return 0;
        default:
            std::cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    }

    return 0;
}

