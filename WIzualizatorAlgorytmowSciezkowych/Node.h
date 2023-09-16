#pragma once
#include "Point.h"

// Klasa reprezentuj�ca w�ze� w siatce
class Node {
public:
    Point position; // Pozycja w�z�a na siatce
    Node* parent; // Wska�nik na rodzica w�z�a (u�ywany podczas �ledzenia �cie�ki)
    float cost; // Koszt doj�cia do tego w�z�a
    float heuristic; // Heurystyka (dla algorytmu A*)

    // Statusy w�z�a
    enum class Status {
        UNVISITED,
        OPEN,
        CLOSED,
        START,
        END,
        OBSTACLE,
        PATH
    };

    Status status; // Aktualny status w�z�a

    Node(); // Domy�lny konstruktor
    Node(int x, int y); // Konstruktor z okre�lonymi wsp�rz�dnymi

    // Zwraca ca�kowity koszt w�z�a (koszt + heurystyka)
    float getTotalCost() const { return cost + heuristic; }

    // Operator por�wnania dla w�z��w
    bool operator==(const Node& other) const { return position == other.position; }
};






