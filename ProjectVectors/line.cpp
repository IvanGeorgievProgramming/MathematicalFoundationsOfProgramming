#include "Line.h"

#include <cmath>

// * Constructors

Line::Line(){
    A = 0;
    B = 0;
    C = 0;

    isParallel = false;
    isPartOfLine = false;
}

Line::Line(double A, double B, double C){
    this->A = A;
    this->B = B;
    this->C = C;

    isParallel = false;
    isPartOfLine = false;
}

Line::Line(Point& p1, Point& p2){
    A = p1.y - p2.y;
    B = p2.x - p1.x;
    C = p1.x * p2.y - p2.x * p1.y;

    isParallel = false;
    isPartOfLine = false;
}

// * Getters

double Line::getA(){
    return A;
}

double Line::getB(){
    return B;
}

double Line::getC(){
    return C;
}

// * Setters

void Line::setA(double A){
    this->A = A;
}

void Line::setB(double B){
    this->B = B;
}

void Line::setC(double C){
    this->C = C;
}

// * Other

// Function to find the intersection point of two lines
Point Line::findIntersectionPoint(Line& l){
    double x = (l.C * B - C * l.B) / (A * l.B - l.A * B);
    double y = (l.A * C - A * l.C) / (A * l.B - l.A * B);

    return Point(x, y);
}

// Function to find the length of part of the line
double Line::findLengthOfPartOfLine(Point& p1, Point& p2){
    double x = p2.x - p1.x;
    double y = p2.y - p1.y;

    return sqrt(x * x + y * y);
}

// Function to find if a point is part of the line
bool Line::isPointPartOfLine(Point& p){
    return (A * p.x + B * p.y + C == 0);
}