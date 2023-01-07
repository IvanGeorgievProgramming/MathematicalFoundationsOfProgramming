#ifndef LINE_H
#define LINE_H

#include "vector.h"

class Line {
private:
    // * Variables
    double A, B, C;

public:
    // * Constructors
    Line();
    Line(const Point p, const Vector& v);
    Line(const Point p1, const Point p2);
    Line(const Line& other);
    Line operator=(const Line& other);

    // * Getters
    double getA() const;
    double getB() const;
    double getC() const;

    // * Setters
    void setA(double A);
    void setB(double B);
    void setC(double C);

    // * Methods
	bool are_parallel(const Line& other) const;
    bool is_orthogonal(const Line& other) const;

	Vector colinear() const;
    Vector orthogonal() const;

    Line parallel(const Point p) const;
    Line orthogonal(const Point p) const;
};

#endif