#ifndef FIELD_H
#define FIELD_H

#include "point.h"
#include "vector.h"
#include "line.h"
#include "ball.h"

class Field{
private:
    // * Variables
    Point startingPosition;
    Point edges[4];
    Line borders[4];
    Ball ball;
    Point innerEdges[4];
    Line innerBorders[4];

public:
    // * Constructors
    Field();
    Field(Point edges[4], Ball& ball);

    // * Getters
    Point getStartingPosition();
    Point getEdges(int i);
    Line getBorders(int i);
    Ball getBall();
    Point getInnerEdges(int i);
    Line getInnerBorders(int i);

    // * Other
    // Fuction to move the ball to a target point with a given power
    Point moveBall(Point target, double power);
    // Fuction to hit the ball to a target point with a given power and to bounce it
    void hitBall(Point target, double power);
    // Print the field
    void printField();
};

// Function to find the area of a triangle
double findTriangleArea(Point p1, Point p2, Point p3);
// Function to find if a point is in a rectangle
bool isPointInRectangle(Point p, Point edges[4]);

#endif