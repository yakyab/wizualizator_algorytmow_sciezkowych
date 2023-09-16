#pragma once
#include <vector>
#include "Node.h"

// Klasa reprezentuj�ca siatk�, na kt�rej dzia�aj� algorytmy �cie�kowe
class Grid {
private:
    std::vector<std::vector<Node>> grid; // Dwuwymiarowa tablica w�z��w
    int width, height; // Szeroko�� i wysoko�� siatki

public:
    Grid(int width, int height); // Konstruktor

    Node& getNode(int x, int y); // Zwraca w�ze� o podanych wsp�rz�dnych
    const Node& getNode(int x, int y) const; // Zwraca w�ze� o podanych wsp�rz�dnych (wersja const)

    int getWidth() const; // Zwraca szeroko�� siatki
    int getHeight() const; // Zwraca wysoko�� siatki

    void setStart(int x, int y); // Ustawia w�ze� startowy
    void setEnd(int x, int y); // Ustawia w�ze� ko�cowy
    void setObstacle(int x, int y); // Ustawia przeszkod�
    void clearObstacle(int x, int y); // Czy�ci przeszkod�
    void resetGrid(); // Resetuje siatk�
};


