#include "vector.h"

// * Constructors

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector::Vector(Point p1, Point p2) {
    // !    x = p2.x - p1.x;
    // !    y = p2.y - p1.y;
}

// * Getters

int Vector::getX() const {
    return x;
}

int Vector::getY() const {
    return y;
}

// * Setters

void Vector::setX(int x) {
    this->x = x;
}

void Vector::setY(int y) {
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