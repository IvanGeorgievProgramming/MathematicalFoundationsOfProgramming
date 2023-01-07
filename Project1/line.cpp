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
    C = -A * p.x - B * p.y;
}

Line::Line(const Point p1, const Point p2) {
    A = p2.y - p1.y;
    B = p1.x - p2.x;
    C = -A * p1.x - B * p1.y;
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

int Line::getA() const {
    return A;
}

int Line::getB() const {
    return B;
}

int Line::getC() const {
    return C;
}

// * Setters

void Line::setA(int A) {
    this->A = A;
}

void Line::setB(int B) {
    this->B = B;
}

void Line::setC(int C) {
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