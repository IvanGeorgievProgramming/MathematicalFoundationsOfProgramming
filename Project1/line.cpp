#include "line.h"

// * Constructors

Line::Line() {
    A = 0;
    B = 0;
    C = 0;
}

Line::Line(const Point p, const Vector& v) {
    A = v.y;
    B = -v.x;
    C = -A * p.pX - B * p.pY;
}

Line::Line(const Point p1, const Point p2) {
    A = p2.pY - p1.pY;
    B = p1.pX - p2.pX;
    C = -A * p1.pX - B * p1.pY;
}

Line::Line(const Line& other) {
    A = other.A;
    B = other.B;
    C = other.C;
}

Line Line::operator=(const Line& other) {
    if (this != &other) {
        A = other.A;
        B = other.B;
        C = other.C;
    }
    return *this;
}

// * Getters

double Line::getA() const {
    return A;
}

double Line::getB() const {
    return B;
}

double Line::getC() const {
    return C;
}

// * Setters

void Line::setA(double A) {
    this->A = A;
}

void Line::setB(double B) {
    this->B = B;
}

void Line::setC(double C) {
    this->C = C;
}

// * Methods

bool Line::are_parallel(const Line& other) const {
    return A * other.B == B * other.A;
}

bool Line::is_orthogonal(const Line& other) const {
    return A * other.A + B * other.B == 0;
}

Vector Line::colinear() const {
    return Vector(-B, A);
}

Vector Line::orthogonal() const {
    return Vector(A, B);
}

Line Line::parallel(const Point p) const {
    return Line(p, colinear());
}

Line Line::orthogonal(const Point p) const {
    return Line(p, orthogonal());
}