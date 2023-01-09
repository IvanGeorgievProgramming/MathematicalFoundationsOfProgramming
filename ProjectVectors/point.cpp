#include "point.h"

// * Constructors

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

// * Other

// Function that checks if a point is inside a rectangle
bool Point::isPointInsideRectangle(Point& p1, Point& p2, Point& p3, Point& p4){
    return (x >= p1.x && x <= p2.x && y >= p1.y && y <= p3.y);
}

// Operator ==
bool operator==(const Point& p, const Point& p2){
    return (p.x == p2.x && p.y == p2.y);
}

// Operator >>
istream& operator>>(istream& is, Point& p){
    cout << "Enter x: ";
    is >> p.x;
    cout << "Enter y: ";
    is >> p.y;

    return is;
}

// Operator <<
ostream& operator<<(ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";

    return os;
}