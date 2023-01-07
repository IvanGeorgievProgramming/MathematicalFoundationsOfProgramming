#include "point.h";

// * Constructors

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// * Getters

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

// * Setters

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}