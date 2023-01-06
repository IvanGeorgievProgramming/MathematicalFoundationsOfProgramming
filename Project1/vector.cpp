#include "vector.h"

// TODO - constructs vector from 2 points
// Подаваме две точки и изваждаме координатите на едната от координатите на другата
Vector::Vector(const Point p1, const Point p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
}

// TODO - returns the sum of two vectors (which is also e vector)
// Събираме x с other.x и y с other.y. Връщаме нов вектор със съответните координати
Vector Vector::sum(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
}

// TODO - returns the product of a vector and a number (which is also e vector)
// Връщаме вектор, чиито координати са произведението на x и num и произведението на y и num
Vector Vector::times_num(int num) const {
    return Vector(x * num, y * num);
}

// TODO - returns a boolean value, answering the question whether the current 
// vector and another ("other") are collinear
// Умножаваме x с other.y и other.x с y. Ако са равни, то векторите са колинеарни и по този начин връщаме 0 (true)
// (Това е малко по-променена версия на формулата за колинеарност на вектори)
// x * other.y - y * other.x == 0     =>     x * other.y == y * other.x
bool Vector::is_colinear(const Vector& other) const {
    return x * other.y == y * other.x;
}

// TODO - returns the length of the current vector
// Връщаме корен квадратен от сумата на квадратите на координатите на вектора
double Vector::length() const {
    return sqrt(x * x + y * y);
}

// TODO - returns the dot(scalar) product of the current vector and another
// Умножаваме x с other.x и y с other.y. Събираме получените числа и връщаме резултата
int Vector::dot_product(const Vector& other) const {
    return x * other.x + y * other.y;
}

// TODO - finds the area of a triangle given two vectors denoting two of its sides
// Намираме всички страни на триъгълника, намираме полупериметъра и използваме формулата за лице на триъгълник на Херон
int area(const Vector v1, const Vector v2) {
    double a = v1.length();
    double b = v2.length();
    double c = (v1.sum(v2)).length();
    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}