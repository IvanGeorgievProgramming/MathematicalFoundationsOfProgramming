#ifndef VECTOR_H
#define VECTOR_H
#include "point.h"

class Vector {
private:
    int x, y;

public:
    // * Constructors
    Vector();
    Vector(int x, int y);
    Vector(Point p1, Point p2);

    // * Getters
    int getX() const;
    int getY() const;

    // * Setters
    void setX(int x);
    void setY(int y);

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