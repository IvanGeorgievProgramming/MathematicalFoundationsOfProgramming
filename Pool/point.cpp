#include "point.h"

// * Constructors

// Default constructor
Point::Point(){
    // Adding default values to the point
    this->pX = 0;
    this->pY = 0;
}

// Constructor with parameters
Point::Point(double pX, double pY){
    // Giving values to the point
    this->pX = pX;
    this->pY = pY;
}

// Copy constructor
Point::Point(Point& other){
    // Copying values from the other point
    this->pX = other.pX;
    this->pY = other.pY;
}

// Operator =
Point &Point::operator=(Point& other){
    // Checking if the objects are the same
    if(this != &other){
        // Copying the values from the other object
        this->pX = other.pX;
        this->pY = other.pY;
    }
    
    // Returning the object
    return *this;
}

// * Getters

// Getter for X coordinate of the point
double Point::getpX(){
    // Returning the x coordinate of the point
    return this->pX;
}

// Getter for the Y coordinate of the point
double Point::getpY(){
    // Returning the y coordinate of the point
    return this->pY;
}

// * Setters

// Setter for the X coordinate of the point
void Point::setpX(double pX){
    // Setting the x coordinate of the point
    this->pX = pX;
}

// Setter for the Y coordinate of the point
void Point::setpY(double pY){
    // Setting the y coordinate of the point
    this->pY = pY;
}

// * Methods

// Method for printing the point
void Point::printPoint(){
    // Printing the point
    cout << "(" << this->pX << ", " << this->pY << ")" << endl;
}