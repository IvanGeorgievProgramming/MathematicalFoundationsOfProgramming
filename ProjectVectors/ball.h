#ifndef BALL_H
#define BALL_H

#include "point.h"

struct Ball {
    // * Variables
    Point center;
    double diameter;

    // * Constructors
    Ball();
    Ball(Point& center, double diameter);

    // * Getters
    Point getCenter();
    double getDiameter();

    // * Setters
    void setCenter(Point& center);
    void setDiameter(double diameter);

    // * Other
    // Operator >>
    friend istream& operator>>(istream& is, Ball& b);
    // Operator <<
    friend ostream& operator<<(ostream& os, const Ball& b);
};

#endif