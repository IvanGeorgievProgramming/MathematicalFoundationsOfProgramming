#include "table.h"

// * Constructors

// Default constructor
Table::Table(){
    // Adding a default starting position
    Point point = Point(280, 70);
    this->startingPosition = point;

    // Adding a default ball
    double radius = 0;
    Ball ball = Ball(startingPosition.getpX(), startingPosition.getpY(), radius);
    this->ball = ball;

    // Adding a default edges
    Point edge1 = Point(0, 0);
    Point edge2 = Point(320, 0);
    Point edge3 = Point(320, 160);
    Point edge4 = Point(0, 160);
    this->edge[0] = edge1;
    this->edge[1] = edge2;
    this->edge[2] = edge3;
    this->edge[3] = edge4;

    // Adding a default border
    Line line1 = Line(edge1, edge2);
    Line line2 = Line(edge2, edge3);
    Line line3 = Line(edge3, edge4);
    Line line4 = Line(edge4, edge1);
    this->border[0] = line1;
    this->border[1] = line2;
    this->border[2] = line3;
    this->border[3] = line4;

    // Adding a default ball edges
    Point ballEdge1 = Point(edge1.getpX() + ball.getRadius(), edge1.getpY() + ball.getRadius());
    Point ballEdge2 = Point(edge2.getpX() - ball.getRadius(), edge2.getpY() + ball.getRadius());
    Point ballEdge3 = Point(edge3.getpX() - ball.getRadius(), edge3.getpY() - ball.getRadius());
    Point ballEdge4 = Point(edge4.getpX() + ball.getRadius(), edge4.getpY() - ball.getRadius());
    this->ballEdge[0] = ballEdge1;
    this->ballEdge[1] = ballEdge2;
    this->ballEdge[2] = ballEdge3;
    this->ballEdge[3] = ballEdge4;

    // Adding a default ball border
    Line ballLine1 = Line(ballEdge1, ballEdge2);
    Line ballLine2 = Line(ballEdge2, ballEdge3);
    Line ballLine3 = Line(ballEdge3, ballEdge4);
    Line ballLine4 = Line(ballEdge4, ballEdge1);
    this->ballBorder[0] = ballLine1;
    this->ballBorder[1] = ballLine2;
    this->ballBorder[2] = ballLine3;
    this->ballBorder[3] = ballLine4;

    // Checking if the lenght of the borders are equal
    double len[4] = {this->border[0].getLength(), this->border[1].getLength(), this->border[2].getLength(), this->border[3].getLength()};
    if (len[0] != len[2] || len[1] != len[3]) {
        throw 1;
    }
    // Checking if the lenght of the borders are in the right proportion (2:1)
    if (len[0] != 2 * len[1] || len[2] != 2 * len[3]) {
        if(len[1] != 2 * len[0] || len[3] != 2 * len[2]){
            throw 2;
        }
    }
    // Checking if the borders are parallel
    if(this->border[0].areParallel(this->border[2]) == false || this->border[1].areParallel(this->border[3]) == false){
        throw 3;
    }
    // TODO: Check if the ball is inside the edges
    
}

// Constructor with parameters
Table::Table(Point& startingPosition,  Ball& ball,  Point edge[4]){
    // Giving values to the starting position
    this->startingPosition = startingPosition;

    // Giving values to the ball
    this->ball = ball;

    // Giving values to the edges
    for (int i = 0; i < 4; i++) {
        this->edge[i] = edge[i];
    }

    // Making the borders from the given edges
    Line line1 = Line(edge[0], edge[1]);
    Line line2 = Line(edge[1], edge[2]);
    Line line3 = Line(edge[2], edge[3]);
    Line line4 = Line(edge[3], edge[0]);
    // Giving values to the borders
    this->border[0] = line1;
    this->border[1] = line2;
    this->border[2] = line3;
    this->border[3] = line4;

    // Making the ball edges from the given edges that are equal to the normal edges - the radius of the ball
    Point ballEdge1 = Point(edge[0].getpX() + ball.getRadius(), edge[0].getpY() + ball.getRadius());
    Point ballEdge2 = Point(edge[1].getpX() - ball.getRadius(), edge[1].getpY() + ball.getRadius());
    Point ballEdge3 = Point(edge[2].getpX() - ball.getRadius(), edge[2].getpY() - ball.getRadius());
    Point ballEdge4 = Point(edge[3].getpX() + ball.getRadius(), edge[3].getpY() - ball.getRadius());
    // Giving values to the ball edges
    this->ballEdge[0] = ballEdge1;
    this->ballEdge[1] = ballEdge2;
    this->ballEdge[2] = ballEdge3;
    this->ballEdge[3] = ballEdge4;

    // Making the ball borders from the given ball edges
    Line ballLine1 = Line(ballEdge1, ballEdge2);
    Line ballLine2 = Line(ballEdge2, ballEdge3);
    Line ballLine3 = Line(ballEdge3, ballEdge4);
    Line ballLine4 = Line(ballEdge4, ballEdge1);
    // Giving values to the ball borders
    this->ballBorder[0] = ballLine1;
    this->ballBorder[1] = ballLine2;
    this->ballBorder[2] = ballLine3;
    this->ballBorder[3] = ballLine4;

    // Checking if the lenght of the borders are equal
    double len[4] = {this->border[0].getLength(), this->border[1].getLength(), this->border[2].getLength(), this->border[3].getLength()};
    if (len[0] != len[2] || len[1] != len[3]) {
        throw 1;
    }
    // Checking if the lenght of the borders are in the right proportion (2:1)
    if (len[0] != 2 * len[1] || len[2] != 2 * len[3]) {
        if(len[1] != 2 * len[0] || len[3] != 2 * len[2]){
            throw 2;
        }
    }
    // Checking if the borders are parallel
    if(this->border[0].areParallel(this->border[2]) == false || this->border[1].areParallel(this->border[3]) == false){
        throw 3;
    }
    // TODO: Check if the ball is inside the edges
}

// Copy constructor
Table::Table(Table& other){
    // Copying the starting position
    this->startingPosition = other.startingPosition;

    // Copying the ball
    this->ball = other.ball;

    // Copying the edges, borders, ball edges and borders
    for (int i = 0; i < 4; i++) {
        this->edge[i] = other.edge[i];
        this->border[i] = other.border[i];
        this->ballEdge[i] = other.ballEdge[i];
        this->ballBorder[i] = other.ballBorder[i];
    }
}

// Operator =
Table &Table::operator=(Table& other){
    // Checking if the object is not the same
    if(this != &other){
        // Copying the starting position
        this->startingPosition = other.startingPosition;

        // Copying the ball
        this->ball = other.ball;

        // Copying the edges, borders, ball edges and borders
        for (int i = 0; i < 4; i++) {
            this->edge[i] = other.edge[i];
            this->border[i] = other.border[i];
            this->ballEdge[i] = other.ballEdge[i];
            this->ballBorder[i] = other.ballBorder[i];
        }
    }

    // Returning the object
    return *this;
}

// * Getters

// Getter for the starting position
Point Table::getStartingPosition() {
    // Returning the starting position
    return this->startingPosition;
}

// Getter for the ball
Ball Table::getBall() {
    // Returning the ball
    return this->ball;
}

// Getter for the edges
Point Table::getEdge(int index) {
    // Returning the edge
    return this->edge[index];
}

// Getter for the borders
Line Table::getBorder(int index) {
    // Returning the border
    return this->border[index];
}

// Getter for the ball edges
Point Table::getBallEdge(int index) {
    // Returning the ball edge
    return this->ballEdge[index];
}

// Getter for the ball borders
Line Table::getBallBorder(int index) {
    // Returning the ball border
    return this->ballBorder[index];
}

// * Setters

// Setter for the starting position
void Table::setStartingPosition(Point& startingPosition){
    // Setting the starting position
    this->startingPosition = startingPosition;
}

// Setter for the ball
void Table::setBall(Ball& ball){
    // Setting the ball
    this->ball = ball;
}

// Setter for the edges
void Table::setEdge(int index, Point& edge){
    // Setting the edge
    this->edge[index] = edge;
}

// Setter for the borders
void Table::setBorder(int index, Line& border){
    // Setting the border
    this->border[index] = border;
}

// Setter for the ball edges
void Table::setBallEdge(int index, Point& ballEdge){
    // Setting the ball edge
    this->ballEdge[index] = ballEdge;
}

// Setter for the ball borders
void Table::setBallBorder(int index, Line& ballBorder){
    // Setting the ball border
    this->ballBorder[index] = ballBorder;
}

// * Methods

// Method for printing the table
void Table::printTable() {
    // Printing the table
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
