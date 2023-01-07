#include "point.h";

// * Constructors

Point::Point() {
    pX = 0;
    pY = 0;
}

Point::Point(double pX, double pY) {
    this->pX = pX;
    this->pY = pY;
}

Point::Point(const Point& other) {
    pX = other.pX;
    pY = other.pY;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        pX = other.pX;
        pY = other.pY;
    }
    return *this;
}

// * Getters

double Point::getpX() const{
    return pX;
}

double Point::getpY() const{
    return pY;
}

// * Setters

void Point::setpX(double pX) {
    this->pX = pX;
}

void Point::setpY(double pY) {
    this->pY = pY;
}