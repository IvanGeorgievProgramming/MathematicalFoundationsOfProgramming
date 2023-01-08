#include "ball.h"

// * Constructors

Ball::Ball(){
    this->radius = 0;
}

Ball::Ball(double pX, double pY, double radius) : Point(pX, pY){
    this->radius = radius;
}

Ball::Ball( Point& p, double radius) : Point(p){
    this->radius = radius;
}

Ball::Ball( Ball& other) : Point(other){
    this->radius = other.radius;
}

Ball &Ball::operator=( Ball& other){
    if(this != &other){
        Point::operator=(other);
        this->radius = other.radius;
    }

    return *this;
}

// * Getters

double Ball::getRadius(){
    return this->radius;
}

// * Setters

void Ball::setRadius(double radius){
    this->radius = radius;
}

// * Methods

void Ball::printBall(){
    Point::printPoint();
    cout << "Radius: " << this->radius << endl;
}