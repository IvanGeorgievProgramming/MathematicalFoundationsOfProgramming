#include "table.h"

// * Constructors

Table::Table(){
    Point point = Point(0, 0);
    this->startingPosition = point;

    Ball ball = Ball(0, 0, 0);
    this->ball = ball;

    Point edge1 = Point(0, 0);
    Point edge2 = Point(0, 0);
    Point edge3 = Point(0, 0);
    Point edge4 = Point(0, 0);
    this->edge[0] = edge1;
    this->edge[1] = edge2;
    this->edge[2] = edge3;
    this->edge[3] = edge4;

    Line line1 = Line(edge1, edge2);
    Line line2 = Line(edge2, edge3);
    Line line3 = Line(edge3, edge4);
    Line line4 = Line(edge4, edge1);
    this->border[0] = line1;
    this->border[1] = line2;
    this->border[2] = line3;
    this->border[3] = line4;
}

Table::Table(Point& startingPosition,  Ball& ball,  Point edge[4]){
    this->startingPosition = startingPosition;

    this->ball = ball;

    for (int i = 0; i < 4; i++) {
        this->edge[i] = edge[i];
    }

    Line line1 = Line(edge[0], edge[1]);
    Line line2 = Line(edge[1], edge[2]);
    Line line3 = Line(edge[2], edge[3]);
    Line line4 = Line(edge[3], edge[0]);

    this->border[0] = line1;
    this->border[1] = line2;
    this->border[2] = line3;
    this->border[3] = line4;
}

Table::Table(Table& other){
    this->startingPosition = other.startingPosition;

    this->ball = other.ball;

    for (int i = 0; i < 4; i++) {
        this->edge[i] = other.edge[i];
        this->border[i] = other.border[i];
    }
}

Table &Table::operator=(Table& other){
    if(this != &other){
        this->startingPosition = other.startingPosition;

        this->ball = other.ball;

        for (int i = 0; i < 4; i++) {
            this->edge[i] = other.edge[i];
            this->border[i] = other.border[i];
        }
    }

    return *this;
}

// * Getters

Point Table::getStartingPosition() {
    return this->startingPosition;
}

Ball Table::getBall() {
    return this->ball;
}

Point Table::getEdge(int index) {
    return this->edge[index];
}

Line Table::getBorder(int index) {
    return this->border[index];
}

// * Setters

void Table::setStartingPosition(Point& startingPosition){
    this->startingPosition = startingPosition;
}

void Table::setBall(Ball& ball){
    this->ball = ball;
}

void Table::setEdge(int index, Point& edge){
    this->edge[index] = edge;
}

void Table::setBorder(int index, Line& border){
    this->border[index] = border;
}

// * Methods

void Table::printTable() {
    cout << "Starting position: ";
    this->startingPosition.printPoint();

    cout << endl << "Ball: ";
    this->ball.printBall();

    cout << endl << "Edges: " << endl;
    for (int i = 0; i < 4; i++) {
        this->edge[i].printPoint();
    }
    
    cout << endl << "Borders: " << endl;
    for (int i = 0; i < 4; i++) {
        this->border[i].printLine();
    }
}