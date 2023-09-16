#pragma once
#include <vector>
#include "Node.h"

// Klasa reprezentuj¹ca siatkê, na której dzia³aj¹ algorytmy œcie¿kowe
class Grid {
private:
    std::vector<std::vector<Node>> grid; // Dwuwymiarowa tablica wêz³ów
    int width, height; // Szerokoœæ i wysokoœæ siatki

public:
    Grid(int width, int height); // Konstruktor

    Node& getNode(int x, int y); // Zwraca wêze³ o podanych wspó³rzêdnych
    const Node& getNode(int x, int y) const; // Zwraca wêze³ o podanych wspó³rzêdnych (wersja const)

    int getWidth() const; // Zwraca szerokoœæ siatki
    int getHeight() const; // Zwraca wysokoœæ siatki

    void setStart(int x, int y); // Ustawia wêze³ startowy
    void setEnd(int x, int y); // Ustawia wêze³ koñcowy
    void setObstacle(int x, int y); // Ustawia przeszkodê
    void clearObstacle(int x, int y); // Czyœci przeszkodê
    void resetGrid(); // Resetuje siatkê
};


