#include "Grid.h"

Grid::Grid(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<Node>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = Node(x, y);
        }
    }
}

Node& Grid::getNode(int x, int y) {
    return grid[y][x];
}

const Node& Grid::getNode(int x, int y) const {
    return grid[y][x];
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

void Grid::setStart(int x, int y) {
    grid[y][x].status = Node::Status::START;
}

void Grid::setEnd(int x, int y) {
    grid[y][x].status = Node::Status::END;
}

void Grid::setObstacle(int x, int y) {
    grid[y][x].status = Node::Status::OBSTACLE;
}

void Grid::clearObstacle(int x, int y) {
    grid[y][x].status = Node::Status::UNVISITED;
}

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
