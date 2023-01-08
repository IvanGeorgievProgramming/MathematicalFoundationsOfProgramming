#ifndef BALL_H
#define BALL_H

#include <iostream>

#include "point.h"

using namespace std;

class Ball : public Point{
private:
    // * Variables
    double radius;

public:
    // * Constructors
    Ball();
    Ball(double pX, double pY, double radius);
    Ball(Point& p, double radius);
    Ball(Ball& other);
    Ball &operator=(Ball& other);

    // * Getters
    double getRadius();

    // * Setters
    void setRadius(double radius);

    // * Methods
    void printBall();

    // * Friends
    friend class Point;
    friend class Line;
    friend class Vector;
    friend class Table;
};

#endif