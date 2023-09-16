#include "Grid.h"

// Konstruktor klasy Grid, inicjalizuje siatkê o podanej szerokoœci i wysokoœci
Grid::Grid(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<Node>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = Node(x, y);
        }
    }
}

// Zwraca wêze³ o podanych wspó³rzêdnych
Node& Grid::getNode(int x, int y) {
    return grid[y][x];
}

// Zwraca wêze³ o podanych wspó³rzêdnych (wersja const)
const Node& Grid::getNode(int x, int y) const {
    return grid[y][x];
}

// Zwraca szerokoœæ siatki
int Grid::getWidth() const {
    return width;
}

// Zwraca wysokoœæ siatki
int Grid::getHeight() const {
    return height;
}

// Ustawia wêze³ startowy na siatce
void Grid::setStart(int x, int y) {
    grid[y][x].status = Node::Status::START;
}

// Ustawia wêze³ koñcowy na siatce
void Grid::setEnd(int x, int y) {
    grid[y][x].status = Node::Status::END;
}

// Ustawia przeszkodê na siatce
void Grid::setObstacle(int x, int y) {
    grid[y][x].status = Node::Status::OBSTACLE;
}

// Czyœci przeszkodê na siatce
void Grid::clearObstacle(int x, int y) {
    grid[y][x].status = Node::Status::UNVISITED;
}

// Resetuje siatkê do stanu pocz¹tkowego
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

