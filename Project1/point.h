#ifndef POINT_H
#define POINT_H

#include <fstream>
#include <cmath>

class Point{
private:
    // Variables
    int x, y;
	
public:
    // Constructors
	Point();
    Point(int x, int y);
    Point(const Point& other);
    Point &operator=(const Point& other);

    // Getters
    int getX();
    int getY();

    // Setters
    void setX(int x);
    void setY(int y);

    // Friends
    friend class Line;
};

#endif