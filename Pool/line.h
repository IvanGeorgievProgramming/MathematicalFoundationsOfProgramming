#ifndef LINE_H
#define LINE_H

#include <iostream>

#include "point.h"
#include "vector.h"

using namespace std;

class Line{
private:
    // * Variables
    double A, B, C;

public:
    // * Constructors
    Line();
    Line(double A, double B, double C);
    Line(Point p1, Point p2);
    Line(Vector& v, Point& p);
    Line(Line& other);
    Line &operator=(Line& other);

    // * Getters
    double getA();
    double getB();
    double getC();

    // * Setters
    void setA(double A);
    void setB(double B);
    void setC(double C);

    // * Methods
    void printLine();

    bool are_parallel(Line& other);
    bool is_orthogonal(Line& other);

	Vector colinear();
    Vector orthogonal();

    Line parallel(Point p);
    Line orthogonal(Point p);

    // * Friends
    friend class Point;
    friend class Vector;
    friend class Ball;
    friend class Table;
};

#endif