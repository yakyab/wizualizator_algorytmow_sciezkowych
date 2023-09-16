#pragma once

// Struktura reprezentuj¹ca punkt w siatce
struct Point {
    int x, y; // Wspó³rzêdne punktu

    Point() : x(0), y(0) {} // Domyœlny konstruktor
    Point(int x, int y) : x(x), y(y) {} // Konstruktor z okreœlonymi wspó³rzêdnymi

    // Operatory porównania
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};


