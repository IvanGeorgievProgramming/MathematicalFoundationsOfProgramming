#include "line.h"

// * Constructors

// Default constructor
Line::Line(){
    // Adding default values to the line
    this->A = 0;
    this->B = 0;
    this->C = 0;
}

// Constructor with parameters 
Line::Line(double A, double B, double C){
    // Giving values to the line
    this->A = A;
    this->B = B;
    this->C = C;
}

// Constructor with parameters (2 points)
Line::Line(Point p1, Point p2){
    // Giving values to the line
    this->A = p1.getpY() - p2.getpY();
    this->B = p2.getpX() - p1.getpX();
    this->C = p1.getpX() * p2.getpY() - p2.getpX() * p1.getpY();
}

// Constructor with parameters (vector and point)
Line::Line(Vector& v, Point& p){
    // Giving values to the line
    this->A = v.getvY();
    this->B = -v.getvX();
    this->C = -(this->A) * p.getpX() - (this->B) * p.getpY();
}

// Copy constructor
Line::Line(Line& other){
    // Copying values from the other line
    this->A = other.A;
    this->B = other.B;
    this->C = other.C;
}

// Operator =
Line &Line::operator=(Line& other){
    // Checking if the objects are the same
    if(this != &other){
        // Copying the values from the other object
        this->A = other.A;
        this->B = other.B;
        this->C = other.C;
    }

    // Returning the object
    return *this;
}

// * Getters

// Getter for the A
double Line::getA(){
    return this->A;
}

// Getter for the B
double Line::getB(){
    return this->B;
}

// Getter for the C
double Line::getC(){
    return this->C;
}

// * Setters

// Setter for the A
void Line::setA(double A){
    this->A = this->A;
}

// Setter for the B
void Line::setB(double B){
    this->B = this->B;
}

// Setter for the C
void Line::setC(double C){
    this->C = this->C;
}

// * Methods

// Method for printing the line
void Line::printLine(){
    cout << "(" << this->A << ", " << this->B << "), (" << this->C << ")" << endl;
}

// Method for checking if the lines are parallel
bool Line::areParallel(Line& other){
    return (this->A * other.B == this->B * other.A);
}

// Method for checking if the lines are orthogonal
bool Line::isOrthogonal(Line& other){
    return (this->A * other.A + this->B * other.B == 0);
}

// Method for checking if the lines are colinear
Vector Line::colinear(){
    return Vector(this->A, this->B);
}

// Method for checking if the lines are orthogonal
Vector Line::orthogonal(){
    return Vector(-this->B, this->A);
}

// Method for finding the parallel line
Line Line::parallel(Point p){
    return Line(this->A, this->B, -(this->A) * p.getpX() - (this->B) * p.getpY());
}

// Method for finding the orthogonal line
Line Line::orthogonal(Point p){
    return Line(-this->B, this->A, -(this->B) * p.getpX() + (this->A) * p.getpY());
}

// Method for finding the length of the line
double Line::getLength(){
    return sqrt(this->A * this->A + this->B * this->B);
}