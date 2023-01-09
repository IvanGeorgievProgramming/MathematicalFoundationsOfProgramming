#include "vector.h"

#include <cmath>

// * Constructors

Vector::Vector(){
    x = 0;
    y = 0;
}

Vector::Vector(double x, double y){
    this->x = x;
    this->y = y;
}

Vector::Vector(Point& p1, Point& p2){
    x = p2.x - p1.x;
    y = p2.y - p1.y;
}

// * Getters

double Vector::getX(){
    return x;
}

double Vector::getY(){
    return y;
}

// * Setters

void Vector::setX(double x){
    this->x = x;
}

void Vector::setY(double y){
    this->y = y;
}

// * Other

// Function to find the length of the vector
double Vector::findLenght(){
    return sqrt(x * x + y * y);
}

// Function to find the new vector end using its start and length
Point Vector::findVectorEnd(Point& p){
    return Point(p.x + x, p.y + y);
}

// Function to find the intersection between a vector and a line
Point Vector::findIntersectionPoint(Line& l){
    double x = (l.getC() * y - l.getB() * x) / (l.getA() * y - l.getB() * x);
    double y = (l.getA() * x - l.getC() * x) / (l.getA() * y - l.getB() * x);

    return Point(x, y);
}

// Function to find the angle between two vectors
double Vector::findAngle(Vector& v){
    return acos((x * v.x + y * v.y) / (findLenght() * v.findLenght()));
}

// Operator *
Vector Vector::operator*(double d){
    return Vector(x * d, y * d);
}

// Operator /
Vector Vector::operator/(double d){
    return Vector(x / d, y / d);
}