#include "ball.h"

// * Constructors

// Default constructor
Ball::Ball(){
    // Adding a default radius
    this->radius = 0;
}

// Constructor with parameters
Ball::Ball(double pX, double pY, double radius) : Point(pX, pY){
    // Giving values to the radius
    this->radius = radius;
}

// Constructor with parameters
Ball::Ball(Point& p, double radius) : Point(p){
    // Giving values to the radius
    this->radius = radius;
}

// Copy constructor
Ball::Ball( Ball& other) : Point(other){
    // Copying the radius
    this->radius = other.radius;
}

Ball &Ball::operator=( Ball& other){
    // Checking if the objects are the same
    if(this != &other){
        // Copying the values from the other object
        Point::operator=(other);
        this->radius = other.radius;
    }

    // Returning the object
    return *this;
}

// * Getters

// Getter for the radius
double Ball::getRadius(){
    // Returning the radius
    return this->radius;
}

// * Setters

// Setter for the radius
void Ball::setRadius(double radius){
    // Setting the radius
    this->radius = radius;
}

// * Methods

// Method for printing the ball
void Ball::printBall(){
    // Printing the ball
    Point::printPoint();
    cout << "Radius: " << this->radius << endl;
}