#include "field.h"

#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

// * Constructors

Field::Field(){
    startingPosition = Point(280, 70);

    edges[0] = Point(0, 0);
    edges[1] = Point(320, 0);
    edges[2] = Point(320, 160);
    edges[3] = Point(0, 160);

    borders[0] = Line(edges[0], edges[1]);
    borders[1] = Line(edges[1], edges[2]);
    borders[2] = Line(edges[2], edges[3]);
    borders[3] = Line(edges[3], edges[0]);

    ball = Ball(startingPosition, 0);

    innerEdges[0] = Point(edges[0].x - ball.diameter, edges[0].y - ball.diameter);
    innerEdges[1] = Point(edges[1].x + ball.diameter, edges[1].y - ball.diameter);
    innerEdges[2] = Point(edges[2].x + ball.diameter, edges[2].y + ball.diameter);
    innerEdges[3] = Point(edges[3].x - ball.diameter, edges[3].y + ball.diameter);

    innerBorders[0] = Line(innerEdges[0], innerEdges[1]);
    innerBorders[1] = Line(innerEdges[1], innerEdges[2]);
    innerBorders[2] = Line(innerEdges[2], innerEdges[3]);
    innerBorders[3] = Line(innerEdges[3], innerEdges[0]);
}

Field::Field(Point edges[4], Ball& ball){
    this->startingPosition = Point(ball.center.x, ball.center.y);

    this->edges[0] = edges[0];
    this->edges[1] = edges[1];
    this->edges[2] = edges[2];
    this->edges[3] = edges[3];

    this->borders[0] = Line(edges[0], edges[1]);
    this->borders[1] = Line(edges[1], edges[2]);
    this->borders[2] = Line(edges[2], edges[3]);
    this->borders[3] = Line(edges[3], edges[0]);

    this->ball = ball;

    this->innerEdges[0] = Point(edges[0].x - ball.diameter, edges[0].y - ball.diameter);
    this->innerEdges[1] = Point(edges[1].x + ball.diameter, edges[1].y - ball.diameter);
    this->innerEdges[2] = Point(edges[2].x + ball.diameter, edges[2].y + ball.diameter);
    this->innerEdges[3] = Point(edges[3].x - ball.diameter, edges[3].y + ball.diameter);

    this->innerBorders[0] = Line(innerEdges[0], innerEdges[1]);
    this->innerBorders[1] = Line(innerEdges[1], innerEdges[2]);
    this->innerBorders[2] = Line(innerEdges[2], innerEdges[3]);
    this->innerBorders[3] = Line(innerEdges[3], innerEdges[0]);
}

// * Getters

Point Field::getStartingPosition(){
    return startingPosition;
}

Point Field::getEdges(int i){
    return edges[i];
}

Line Field::getBorders(int i){
    return borders[i];
}

Ball Field::getBall(){
    return ball;
}

Point Field::getInnerEdges(int i){
    return innerEdges[i];
}

Line Field::getInnerBorders(int i){
    return innerBorders[i];
}

// * Other

// Fuction to move the ball to a target point with a given power
Point Field::moveBall(Point target, double power){
    Vector v = Vector(target.x - ball.center.x, target.y - ball.center.y);
    v = v * power;
    Point newCenter = v.findVectorEnd(ball.center);

    return newCenter;
}

// Fuction to hit the ball to a target point with a given power and to bounce it
void Field::hitBall(Point target, double power){
    Point newCenter = moveBall(target, power);

    if(isPointInRectangle(newCenter, innerEdges)){
        ball.center = newCenter;
    } 
    else {
        cout << "Ball is out of the field!" << endl;
        /*do{
            // TODO: Find the correct crossing point of the ball with the correct inner border
            // TODO: Find the new position of the ball, which is a reflection of the old position
            // TODO: Make the ball center to be the crossing point
            // TODO: Move the ball center to the new direction
            // TODO: Repeat until the ball is in the field
            if(isPointInRectangle(newCenter, innerEdges)){
                ball.center = newCenter;
            }
            // TODO: Check if the ball hits the corner of the field and if it does, move it to the starting position
        }
        while(!isPointInRectangle(newCenter, innerEdges));*/
    }
}

// Print the field
void Field::printField(){
    cout << "Field:" << endl;
    cout << "Edges: " << endl;
    for(int i = 0; i < 4; i++){
        cout << "Edge " << i << ": " << edges[i].x << ", " << edges[i].y << endl;
    }
    cout << "Ball: " << endl;
    cout << "Center: " << ball.center.x << ", " << ball.center.y << endl;
    cout << "Diameter: " << ball.diameter << endl;
}

// Function to find the area of a triangle
double findTriangleArea(Point p1, Point p2, Point p3){
    double area = abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
    return area;
}

// Function to find if a point is inside a rectangle
bool isPointInRectangle(Point point, Point p[4]){
    Line line;
    double sum = 0;
	double areaOfRectangle = line.findLengthOfPartOfLine(p[0], p[1]) * line.findLengthOfPartOfLine(p[1], p[2]);

	for(int i = 0; i < 4; i++){
		if(i == 3){
			sum += findTriangleArea(p[i], p[0], point);
			break;
		}

		sum += findTriangleArea(p[i], p[i+1], point);
	}

	bool result = areaOfRectangle == sum;

	return result;
}
