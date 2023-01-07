#ifndef POINT_H
#define POINT_H

#include <fstream>
#include <cmath>

class Point{
private:
    // * Variables
    double pX, pY;
	
public:
    // * Constructors
	Point();
    Point(double pX, double pY);
    Point(const Point& other);
    Point &operator=(const Point& other);

    // * Getters
    double getpX() const;
    double getpY() const;

    // * Setters
    void setpX(double pX);
    void setpY(double pY);

    // * Friends
    friend class Line;
};

#endif