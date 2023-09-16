#pragma once

// Struktura reprezentuj�ca punkt w siatce
struct Point {
    int x, y; // Wsp�rz�dne punktu

    Point() : x(0), y(0) {} // Domy�lny konstruktor
    Point(int x, int y) : x(x), y(y) {} // Konstruktor z okre�lonymi wsp�rz�dnymi

    // Operatory por�wnania
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};


