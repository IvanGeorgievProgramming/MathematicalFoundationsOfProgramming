#include "ball.h"

// * Constructors

Ball::Ball(){
    center = Point();
    diameter = 0;
}

Ball::Ball(Point& center, double diameter){
    this->center = center;
    this->diameter = diameter;
}

// * Getters

Point Ball::getCenter(){
    return center;
}

double Ball::getDiameter(){
    return diameter;
}

// * Setters

void Ball::setCenter(Point& center){
    this->center = center;
}

void Ball::setDiameter(double diameter){
    this->diameter = diameter;
}

// * Other

// Operator >>
istream& operator>>(istream& is, Ball& b){
    cout << "Enter center: ";
    is >> b.center;
    cout << "Enter diameter: ";
    is >> b.diameter;

    return is;
}

// Operator <<
ostream& operator<<(ostream& os, const Ball& b){
    os << "Center: " << b.center << ", Diameter: " << b.diameter;

    return os;
}