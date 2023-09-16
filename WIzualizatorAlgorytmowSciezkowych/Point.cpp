#include "Point.h"

// Operatory por�wnania dla struktury Point
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}



