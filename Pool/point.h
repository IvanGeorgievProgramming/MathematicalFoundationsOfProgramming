#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point{
private:
    // * Variables
    double pX, pY;

public:
    // * Constructors
    Point();
    Point(double pX, double pY);
    Point(Point& other);
    Point &operator=(Point& other);

    // * Getters
    double getpX();
    double getpY();

    // * Setters
    void setpX(double pX);
    void setpY(double pY);

    // * Methods
    void printPoint();
    bool inRectangle(Point p1, Point p2, Point p3, Point p4);

    // * Friends
    friend class Line;
    friend class Vector;
    friend class Ball;
    friend class Table;
};

#endif