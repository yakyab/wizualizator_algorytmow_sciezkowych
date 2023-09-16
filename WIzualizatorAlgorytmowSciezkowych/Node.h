#pragma once
#include "Point.h"

// Klasa reprezentuj¹ca wêze³ w siatce
class Node {
public:
    Point position; // Pozycja wêz³a na siatce
    Node* parent; // WskaŸnik na rodzica wêz³a (u¿ywany podczas œledzenia œcie¿ki)
    float cost; // Koszt dojœcia do tego wêz³a
    float heuristic; // Heurystyka (dla algorytmu A*)

    // Statusy wêz³a
    enum class Status {
        UNVISITED,
        OPEN,
        CLOSED,
        START,
        END,
        OBSTACLE,
        PATH
    };

    Status status; // Aktualny status wêz³a

    Node(); // Domyœlny konstruktor
    Node(int x, int y); // Konstruktor z okreœlonymi wspó³rzêdnymi

    // Zwraca ca³kowity koszt wêz³a (koszt + heurystyka)
    float getTotalCost() const { return cost + heuristic; }

    // Operator porównania dla wêz³ów
    bool operator==(const Node& other) const { return position == other.position; }
};






