#pragma once
#include <vector>
#include "Node.h"

class Grid {
private:
    std::vector<std::vector<Node>> grid;
    int width, height;

public:
    Grid(int width, int height);

    Node& getNode(int x, int y);
    const Node& getNode(int x, int y) const;

    int getWidth() const;
    int getHeight() const;

    void setStart(int x, int y);
    void setEnd(int x, int y);
    void setObstacle(int x, int y);
    void clearObstacle(int x, int y);
    void resetGrid();
};

