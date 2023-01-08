#include "point.h"

// * Constructors

Point::Point(){
    this->pX = 0;
    this->pY = 0;
}

Point::Point(double pX, double pY){
    this->pX = pX;
    this->pY = pY;
}

Point::Point(Point& other){
    this->pX = other.pX;
    this->pY = other.pY;
}

Point &Point::operator=(Point& other){
    if(this != &other){
        this->pX = other.pX;
        this->pY = other.pY;
    }
    
    return *this;
}

// * Getters

double Point::getpX(){
    return this->pX;
}

double Point::getpY(){
    return this->pY;
}

// * Setters

void Point::setpX(double pX){
    this->pX = pX;
}

void Point::setpY(double pY){
    this->pY = pY;
}

// * Methods

void Point::printPoint(){
    cout << "(" << this->pX << ", " << this->pY << ")" << endl;
}