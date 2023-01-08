#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

#include "point.h"

using namespace std;

class Vector{
private:
    // * Variables
    double vX, vY;

public:
    // * Constructors
    Vector();
    Vector(double vX, double vY);
    Vector(double vX, double vY, double power);
    Vector(Point p1, Point p2);
    Vector(Vector& other);
    Vector &operator=(Vector& other);

    // * Getters
    double getvX();
    double getvY();

    // * Setters
    void setvX(double vX);
    void setvY(double vY);

    // * Methods
    void printVector();

    Vector sum(Vector& other);
    Vector times_num(double num);

    bool is_colinear(Vector& other);
    double length();
    int dot_product(Vector& other);

    // * Friends
    friend class Point;
    friend class Line;
    friend class Ball;
    friend class Table;
};

int area(Vector v1, Vector v2);

#endif