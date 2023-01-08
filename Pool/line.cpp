#include "line.h"

// * Constructors

Line::Line(){
    this->A = 0;
    this->B = 0;
    this->C = 0;
}

Line::Line(double A, double B, double C){
    this->A = A;
    this->B = B;
    this->C = C;
}

Line::Line(Point p1, Point p2){
    this->A = p1.getpY() - p2.getpY();
    this->B = p2.getpX() - p1.getpX();
    this->C = p1.getpX() * p2.getpY() - p2.getpX() * p1.getpY();
}

Line::Line(Vector& v, Point& p){
    this->A = v.getvY();
    this->B = -v.getvX();
    this->C = -(this->A) * p.getpX() - (this->B) * p.getpY();
}

Line::Line(Line& other){
    this->A = other.A;
    this->B = other.B;
    this->C = other.C;
}

Line &Line::operator=(Line& other){
    if(this != &other){
        this->A = other.A;
        this->B = other.B;
        this->C = other.C;
    }

    return *this;
}

// * Getters

double Line::getA(){
    return this->A;
}

double Line::getB(){
    return this->B;
}

double Line::getC(){
    return this->C;
}

// * Setters

void Line::setA(double A){
    this->A = this->A;
}

void Line::setB(double B){
    this->B = this->B;
}

void Line::setC(double C){
    this->C = this->C;
}

// * Methods

void Line::printLine(){
    cout << this->A << "x + " << this->B << "y + " << this->C << " = 0" << endl;
}