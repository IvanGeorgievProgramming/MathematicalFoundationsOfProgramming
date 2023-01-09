#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line{
public:
    // * Variables
    double A;
    double B;
    double C;

    bool isParallel;
    bool isPartOfLine;

    // * Constructors
    Line();
    Line(double A, double B, double C);
    Line(Point& p1, Point& p2);

    // * Getters
    double getA();
    double getB();
    double getC();

    // * Setters
    void setA(double A);
    void setB(double B);
    void setC(double C);

    // * Other
    // Function to find the intersection point of two lines
    Point findIntersectionPoint(Line& l);
    // Function to find the length of part of the line
    double findLengthOfPartOfLine(Point& p1, Point& p2);
    // Function to find if a point is part of the line
    bool isPointPartOfLine(Point& p);
};

#endif