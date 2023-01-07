#include "vector.h"

// * Constructors

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector::Vector(const Point p1, const Point p2) {
    // ! x = p2.pX - p1.pX;
    // ! y = p2.pY - p1.pY;
}

// * Getters

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

// * Setters

void Vector::setX(double x) {
    this->x = x;
}

void Vector::setY(double y) {
    this->y = y;
}

// * Methods

Vector Vector::sum(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::times_num(int num) const {
    return Vector(x * num, y * num);
}

bool Vector::is_colinear(const Vector& other) const {
    return x * other.y == y * other.x;
}

double Vector::length() const {
    return sqrt(x * x + y * y);
}

int Vector::dot_product(const Vector& other) const {
    return x * other.x + y * other.y;
}

int area(const Vector v1, const Vector v2) {
    double a = v1.length();
    double b = v2.length();
    double c = (v1.sum(v2)).length();
    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}