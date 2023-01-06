#include "line.h"

// TODO - constructs a line given a point and a vector
// Използваме формулата за права, която се получава от точка и вектор
Line::Line(const Point p, const Vector& v) {
    A = v.y;
    B = -v.x;
    C = -A * p.x - B * p.y;
}

// TODO - constructs a line given two points
// Използваме формлата за права, която се получава от две точки
Line::Line(const Point p1, const Point p2) {
    A = p2.y - p1.y;
    B = p1.x - p2.x;
    C = -A * p1.x - B * p1.y;
}

// TODO - checks if two lines a parallel to eachother
//Умножавамe A с other.B и B с other.A. Ако са равни, то линиите са паралелни
bool Line::are_parallel(const Line& other) const {
    return A * other.B == B * other.A;
}

// TODO - checks if two lines are orthogonal (perpendicular)
//Умножавамe A с other.A и B с other.B. Ако сборът на произведенията е равен на 0, то линиите са ортогонални
bool Line::is_orthogonal(const Line& other) const {
    return A * other.A + B * other.B == 0;
}

// TODO - returns the vector that is colinear to the line
//Връщаме вектор, чиито координати са A и -B
Vector Line::colinear() const {
    return Vector(-B, A);
}

// TODO - returns the vector that is orthogonal to the line
//Връщаме вектор, чиито координати са A и B
Vector Line::orthogonal() const {
    return Vector(A, B);
}

// TODO - returns a line, passing through the point p, that is parallel to the line
//Връщаме линия, която минава през точката p и е паралелна на текущата линия
Line Line::parallel(const Point p) const {
    return Line(p, colinear());
}

// TODO - returns a line, passing through the point p, that is orthogonal to the line
//Връщаме линия, която минава през точката p и е ортогонална на текущата линия
Line Line::orthogonal(const Point p) const {
    return Line(p, orthogonal());
}