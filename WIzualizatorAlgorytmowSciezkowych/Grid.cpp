#include "Grid.h"

// Konstruktor klasy Grid, inicjalizuje siatk� o podanej szeroko�ci i wysoko�ci
Grid::Grid(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<Node>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = Node(x, y);
        }
    }
}

// Zwraca w�ze� o podanych wsp�rz�dnych
Node& Grid::getNode(int x, int y) {
    return grid[y][x];
}

// Zwraca w�ze� o podanych wsp�rz�dnych (wersja const)
const Node& Grid::getNode(int x, int y) const {
    return grid[y][x];
}

// Zwraca szeroko�� siatki
int Grid::getWidth() const {
    return width;
}

// Zwraca wysoko�� siatki
int Grid::getHeight() const {
    return height;
}

// Ustawia w�ze� startowy na siatce
void Grid::setStart(int x, int y) {
    grid[y][x].status = Node::Status::START;
}

// Ustawia w�ze� ko�cowy na siatce
void Grid::setEnd(int x, int y) {
    grid[y][x].status = Node::Status::END;
}

// Ustawia przeszkod� na siatce
void Grid::setObstacle(int x, int y) {
    grid[y][x].status = Node::Status::OBSTACLE;
}

// Czy�ci przeszkod� na siatce
void Grid::clearObstacle(int x, int y) {
    grid[y][x].status = Node::Status::UNVISITED;
}

// Resetuje siatk� do stanu pocz�tkowego
void Grid::resetGrid() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x].status = Node::Status::UNVISITED;
            grid[y][x].cost = 0.0f;
            grid[y][x].heuristic = 0.0f;
            grid[y][x].parent = nullptr;
        }
    }
}

