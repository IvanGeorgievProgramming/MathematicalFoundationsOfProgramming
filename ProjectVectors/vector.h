#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"
#include "line.h"

class Vector{
private:
    // * Variables
    double x;
    double y;

public:
    // * Constructors
    Vector();
    Vector(double x, double y);
    Vector(Point& p1, Point& p2);

    // * Getters
    double getX();
    double getY();

    // * Setters
    void setX(double x);
    void setY(double y);

    // * Other
    // Function to find the length of the vector
    double findLenght();
    // Function to find the new vector end using its start and length
    Point findVectorEnd(Point& p);
    // Function to find the intersection between a vector and a line
    Point findIntersectionPoint(Line& l);
    // Function to find the angle between two vectors
    double findAngle(Vector& v);
    // Operator *
    Vector operator*(double d);
    // Operator /
    Vector operator/(double d);
};

#endif