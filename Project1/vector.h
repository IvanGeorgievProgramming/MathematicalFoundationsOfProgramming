#ifndef VECTOR_H
#define VECTOR_H
#include "point.h"

class Vector {
private:
    double x, y;

public:
    // * Constructors
    Vector();
    Vector(double x, double y);
    Vector(const Point p1, const Point p2);

    // * Getters
    double getX() const;
    double getY() const;

    // * Setters
    void setX(double x);
    void setY(double y);

    // * Methods
    Vector sum(const Vector& other) const;
    Vector times_num(int num) const;

    bool is_colinear(const Vector& other) const;
    double length() const;
    int dot_product(const Vector& other) const;

    // * Friends
    friend class Line;
    friend class Point;
};

int area(const Vector v1, const Vector v2);

#endif