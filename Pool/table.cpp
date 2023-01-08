#include "table.h"

// * Constructors

Table::Table(){
    Point point = Point(280, 70);
    this->startingPosition = point;

    Ball ball = Ball(280, 70, 0);
    this->ball = ball;

    Point edge1 = Point(0, 0);
    Point edge2 = Point(320, 0);
    Point edge3 = Point(320, 160);
    Point edge4 = Point(0, 160);
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

    Point ballEdge1 = Point(edge1.getpX() + ball.getRadius(), edge1.getpY() + ball.getRadius());
    Point ballEdge2 = Point(edge2.getpX() - ball.getRadius(), edge2.getpY() + ball.getRadius());
    Point ballEdge3 = Point(edge3.getpX() - ball.getRadius(), edge3.getpY() - ball.getRadius());
    Point ballEdge4 = Point(edge4.getpX() + ball.getRadius(), edge4.getpY() - ball.getRadius());
    this->ballEdge[0] = ballEdge1;
    this->ballEdge[1] = ballEdge2;
    this->ballEdge[2] = ballEdge3;
    this->ballEdge[3] = ballEdge4;

    Line ballLine1 = Line(ballEdge1, ballEdge2);
    Line ballLine2 = Line(ballEdge2, ballEdge3);
    Line ballLine3 = Line(ballEdge3, ballEdge4);
    Line ballLine4 = Line(ballEdge4, ballEdge1);
    this->ballBorder[0] = ballLine1;
    this->ballBorder[1] = ballLine2;
    this->ballBorder[2] = ballLine3;
    this->ballBorder[3] = ballLine4;
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

    Point ballEdge1 = Point(edge[0].getpX() + ball.getRadius(), edge[0].getpY() + ball.getRadius());
    Point ballEdge2 = Point(edge[1].getpX() - ball.getRadius(), edge[1].getpY() + ball.getRadius());
    Point ballEdge3 = Point(edge[2].getpX() - ball.getRadius(), edge[2].getpY() - ball.getRadius());
    Point ballEdge4 = Point(edge[3].getpX() + ball.getRadius(), edge[3].getpY() - ball.getRadius());
    this->ballEdge[0] = ballEdge1;
    this->ballEdge[1] = ballEdge2;
    this->ballEdge[2] = ballEdge3;
    this->ballEdge[3] = ballEdge4;

    Line ballLine1 = Line(ballEdge1, ballEdge2);
    Line ballLine2 = Line(ballEdge2, ballEdge3);
    Line ballLine3 = Line(ballEdge3, ballEdge4);
    Line ballLine4 = Line(ballEdge4, ballEdge1);
    this->ballBorder[0] = ballLine1;
    this->ballBorder[1] = ballLine2;
    this->ballBorder[2] = ballLine3;
    this->ballBorder[3] = ballLine4;

    // TODO: Check if the edges are 1:2
    // TODO: Check if the ball is inside the edges
}

Table::Table(Table& other){
    this->startingPosition = other.startingPosition;

    this->ball = other.ball;

    for (int i = 0; i < 4; i++) {
        this->edge[i] = other.edge[i];
        this->border[i] = other.border[i];
        this->ballEdge[i] = other.ballEdge[i];
        this->ballBorder[i] = other.ballBorder[i];
    }
}

Table &Table::operator=(Table& other){
    if(this != &other){
        this->startingPosition = other.startingPosition;

        this->ball = other.ball;

        for (int i = 0; i < 4; i++) {
            this->edge[i] = other.edge[i];
            this->border[i] = other.border[i];
            this->ballEdge[i] = other.ballEdge[i];
            this->ballBorder[i] = other.ballBorder[i];
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

Point Table::getBallEdge(int index) {
    return this->ballEdge[index];
}

Line Table::getBallBorder(int index) {
    return this->ballBorder[index];
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

void Table::setBallEdge(int index, Point& ballEdge){
    this->ballEdge[index] = ballEdge;
}

void Table::setBallBorder(int index, Line& ballBorder){
    this->ballBorder[index] = ballBorder;
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
