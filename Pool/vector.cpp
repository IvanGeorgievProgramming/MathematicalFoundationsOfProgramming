#include "vector.h"

// * Constructors

// Default constructor
Vector::Vector(){
    // Adding default values to the vector
    this->vX = 0;
    this->vY = 0;
}

// Constructor with parameters
Vector::Vector(double vX, double vY){
    // Giving values to the vector
    this->vX = vX;
    this->vY = vY;
}

// Constructor with parameters (vX, vY, power)
Vector::Vector(double vX, double vY, double power){
    // Giving values to the vector
    this->vX = vX * power;
    this->vY = vY * power;
}

// Constructor with parameters (2 points)
Vector::Vector(Point p1, Point p2){
    // Giving values to the vector
    this->vX = p2.getpX() - p1.getpX();
    this->vY = p2.getpY() - p1.getpY();
}

// Copy constructor
Vector::Vector(Vector& other){
    // Copying values from the other vector
    this->vX = other.vX;
    this->vY = other.vY;
}

// Operator =
Vector &Vector::operator=(Vector& other){
    // Checking if the objects are the same
    if(this != &other){
        // Copying the values from the other object
        this->vX = other.vX;
        this->vY = other.vY;
    }

    // Returning the object
    return *this;
}

// * Getters

// Getter for the X coordinate of the vector
double Vector::getvX(){
    // Returning the x coordinate of the vector
    return this->vX;
}

// Getter for the Y coordinate of the vector
double Vector::getvY(){
    // Returning the y coordinate of the vector
    return this->vY;
}

// * Setters

// Setter for the X coordinate of the vector
void Vector::setvX(double vX){
    // Setting the x coordinate of the vector
    this->vX = vX;
}

// Setter for the Y coordinate of the vector
void Vector::setvY(double vY){
    // Setting the y coordinate of the vector
    this->vY = vY;
}

// * Methods

// Method for printing the vector
void Vector::printVector(){
    cout << "(" << this->vX << ", " << this->vY << ")" << endl;
}

// Method for summing 2 vectors
Vector Vector::sum(Vector& other){
    Vector result;

    result.vX = this->vX + other.vX;
    result.vY = this->vY + other.vY;

    return result;
}

// Method for multiplying a vector by a number
Vector Vector::times_num(double num){
    Vector result;

    result.vX = this->vX * num;
    result.vY = this->vY * num;
    
    return result;
}

// Method for checking if 2 vectors are colinear
bool Vector::is_colinear(Vector& other){
    // Checking if the vectors are colinear
    return this->vX * other.vY == this->vY * other.vX;
}

// Method for getting the length of the vector
double Vector::length(){
    // Returning the length of the vector
    return sqrt(this->vX * this->vX + this->vY * this->vY);
}

// Method for getting the dot product of 2 vectors
int Vector::dot_product(Vector& other){
    return this->vX * other.vX + this->vY * other.vY;
}

int area(Vector v1, Vector v2){
    double a = v1.length();
    double b = v2.length();
    double c = (v1.sum(v2)).length();
    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}