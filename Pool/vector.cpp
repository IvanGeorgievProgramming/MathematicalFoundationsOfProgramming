#include "vector.h"

// * Constructors

Vector::Vector(){
    this->vX = 0;
    this->vY = 0;
}

Vector::Vector(double vX, double vY){
    this->vX = vX;
    this->vY = vY;
}

Vector::Vector(Point p1, Point p2){
    this->vX = p2.getpX() - p1.getpX();
    this->vY = p2.getpY() - p1.getpY();
}

Vector::Vector(Vector& other){
    this->vX = other.vX;
    this->vY = other.vY;
}

Vector &Vector::operator=(Vector& other){
    if(this != &other){
        this->vX = other.vX;
        this->vY = other.vY;
    }

    return *this;
}

// * Getters

double Vector::getvX(){
    return this->vX;
}

double Vector::getvY(){
    return this->vY;
}

// * Setters

void Vector::setvX(double vX){
    this->vX = vX;
}

void Vector::setvY(double vY){
    this->vY = vY;
}

// * Methods

void Vector::printVector(){
    cout << "(" << this->vX << ", " << this->vY << ")" << endl;
}

Vector Vector::sum(Vector& other){
    Vector result;

    result.vX = this->vX + other.vX;
    result.vY = this->vY + other.vY;

    return result;
}

Vector Vector::times_num(int num){
    Vector result;

    result.vX = this->vX * num;
    result.vY = this->vY * num;
    
    return result;
}

bool Vector::is_colinear(Vector& other){
    return this->vX * other.vY == this->vY * other.vX;
}

double Vector::length(){
    return sqrt(this->vX * this->vX + this->vY * this->vY);
}

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