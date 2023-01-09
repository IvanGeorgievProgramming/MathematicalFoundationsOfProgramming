#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

struct Point{
    // * Variables
    double x;
    double y;

    // * Constructors
    Point();
    Point(double x, double y);

    // * Other
    // Function that checks if a point is inside a rectangle
    bool isPointInsideRectangle(Point& p1, Point& p2, Point& p3, Point& p4);
    // Operator ==
    friend bool operator==(const Point& p, const Point& p2);
    // Operator >>
    friend istream& operator>>(istream& is, Point& p);
    // Operator <<
    friend ostream& operator<<(ostream& os, const Point& p);
};

#endif