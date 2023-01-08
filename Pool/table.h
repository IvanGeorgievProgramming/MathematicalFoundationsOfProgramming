#ifndef TABLE_H
#define TABLE_H

#include <iostream>

#include "point.h"
#include "vector.h"
#include "line.h"
#include "ball.h"

using namespace std;

class Table{
private:
    // * Variables
    Point startingPosition;
    Ball ball;
    Point edge[4];
    Line border[4];

public:
    // * Constructors
    Table();
    Table(Point& startingPosition, Ball& ball, Point edge[4]);
    Table(Table& other);
    Table &operator=(Table& other);

    // * Getters
    Point getStartingPosition();
    Ball getBall();
    Point getEdge(int index);
    Line getBorder(int index);

    // * Setters
    void setStartingPosition(Point& startingPosition);
    void setBall(Ball& ball);
    void setEdge(int index, Point& edge);
    void setBorder(int index, Line& border);
    
    // * Methods
    void printTable();

    // * Friends
    friend class Point;
    friend class Vector;
    friend class Line;
    friend class Ball;
};

#endif
