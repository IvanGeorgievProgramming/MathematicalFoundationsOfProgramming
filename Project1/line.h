#ifndef LINE_H
#define LINE_H

#include "vector.h"

class Line {
private:
    // * Variables
    int A, B, C;

public:
    // * Constructors
    Line();
    Line(const Point p, const Vector& v);
    Line(const Point p1, const Point p2);
    Line(const Line& other);
    Line operator=(const Line& other);

    // * Getters
    int getA() const;
    int getB() const;
    int getC() const;

    // * Setters
    void setA(int A);
    void setB(int B);
    void setC(int C);

    // * Methods
	bool are_parallel(const Line& other) const;
    bool is_orthogonal(const Line& other) const;

	Vector colinear() const;
    Vector orthogonal() const;

    Line parallel(const Point p) const;
    Line orthogonal(const Point p) const;
};

#endif