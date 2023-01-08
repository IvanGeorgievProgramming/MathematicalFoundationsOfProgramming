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

// Method for checking if the point is inside a rectangle
// The rectangale can be recersed
bool Point::inRectangle(Point p1, Point p2, Point p3, Point p4){
    // Checking if the point is inside the rectangle
    if(this->pX >= p1.pX && this->pX <= p2.pX && this->pY >= p1.pY && this->pY <= p3.pY){
        // Returning true
        return true;
    }
    else if(this->pX >= p2.pX && this->pX <= p1.pX && this->pY >= p2.pY && this->pY <= p4.pY){
        // Returning true
        return true;
    }
    else if(this->pX >= p3.pX && this->pX <= p4.pX && this->pY >= p3.pY && this->pY <= p1.pY){
        // Returning true
        return true;
    }
    else if(this->pX >= p4.pX && this->pX <= p3.pX && this->pY >= p4.pY && this->pY <= p2.pY){
        // Returning true
        return true;
    }
    else{
        // Returning false
        return false;
    }
}