#include "Grid.h"
#include "AStar.h"
#include "Dijkstra.h"
#include "BFS.h"
#include "DFS.h"
#include "PathRetracer.h"
#include <iostream>

void displayMenu() {
    std::cout << "Wybierz algorytm:\n";
    std::cout << "1. A*\n";
    std::cout << "2. Dijkstra\n";
    std::cout << "3. BFS\n";
    std::cout << "4. DFS\n";
    std::cout << "5. Wyjscie\n";
}

Point getUserPoint(const std::string& prompt, const Grid& grid) {
    Point p;
    while (true) {
        std::cout << prompt << "\n";
        std::cout << "x: ";
        std::cin >> p.x;
        std::cout << "y: ";
        std::cin >> p.y;
        if (p.x >= 0 && p.x < grid.getWidth() && p.y >= 0 && p.y < grid.getHeight()) {
            return p;
        }
        else {
            std::cout << "Nieprawidlowe wspolrzedne. Sprobuj ponownie.\n";
        }
    }
}

void setObstacles(Grid& grid) {
    int numObstacles;
    std::cout << "Ile przeszkod chcesz dodac? ";
    std::cin >> numObstacles;

    for (int i = 0; i < numObstacles; ++i) {
        Point obstacle = getUserPoint("Podaj wspolrzedne przeszkody:", grid);
        grid.getNode(obstacle.x, obstacle.y).status = Node::Status::OBSTACLE;
    }
}

void displayGrid(const Grid& grid, const Point& start, const Point& end) {
    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            const Node& node = grid.getNode(x, y);
            if (node.position == start) std::cout << "S ";
            else if (node.position == end) std::cout << "E ";
            else if (node.status == Node::Status::OBSTACLE) std::cout << "# ";
            else if (node.status == Node::Status::PATH) std::cout << "* ";
            else if (node.status == Node::Status::CLOSED) std::cout << ". ";
            else std::cout << "- ";
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
            grid.resetGrid();
            start = getUserPoint("Podaj punkt startowy:", grid);
            end = getUserPoint("Podaj punkt koncowy:", grid);
            setObstacles(grid);
            AStar(grid, start, end);

            // Upewnij się, że punkt końcowy został odwiedzony przed wywołaniem retracePath
            if (grid.getNode(end.x, end.y).status != Node::Status::UNVISITED) {
                retracePath(grid, start, end);
            }
            else {
                std::cout << "Nie znaleziono ścieżki od punktu początkowego do końcowego.\n";
            }

            displayGrid(grid, start, end);
            break;
        case 2:
            grid.resetGrid();
            start = getUserPoint("Podaj punkt startowy:", grid);
            end = getUserPoint("Podaj punkt koncowy:", grid);
            setObstacles(grid);
            Dijkstra(grid, start, end);
            retracePath(grid, start, end);
            displayGrid(grid, start, end);
            break;
        case 3:
            grid.resetGrid();
            start = getUserPoint("Podaj punkt startowy:", grid);
            end = getUserPoint("Podaj punkt koncowy:", grid);
            setObstacles(grid);
            BFS(grid, start, end);
            retracePath(grid, start, end);
            displayGrid(grid, start, end);
            break;
        case 4:
            grid.resetGrid();
            start = getUserPoint("Podaj punkt startowy:", grid);
            end = getUserPoint("Podaj punkt koncowy:", grid);
            setObstacles(grid);
            DFS(grid, start, end);
            retracePath(grid, start, end);
            displayGrid(grid, start, end);
            break;
        case 5:
            std::cout << "Do widzenia!\n";
            return 0;
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        }
    }

    return 0;
}







