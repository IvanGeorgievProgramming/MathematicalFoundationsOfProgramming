#include "field.h"

using namespace std;

void printMenu();
Field initializeField();
Field changeField();
void printField(Field field);
void hitBall(Field* field);
void listCommands();

int main(){
    bool isRunning = true;
    bool isInitialized = false;
    bool areEdgesNeeded = true;
    int option;

    Field field;

    while(isRunning){
        printMenu();
        cin >> option;

        if(!isInitialized && option != 1 && option != 5 && option != 6){
            cout << "The field is not initialized" << endl;
            continue;
        }
        
        switch(option){
            case 1:
                if(isInitialized){
                    cout << "The field is already initialized" << endl;
                }
                else{
                    field = initializeField();
                    isInitialized = true;
                }
                break;
            case 2:
                field = changeField();
                break;
            case 3:
                printField(field);
                break;
            case 4:
                hitBall(&field);
                break;
            case 5:
                listCommands();
                break;
            case 6:
                isRunning = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
    
    return 0;
}

void printMenu(){
    cout << endl << "Choose an option:" << endl;
    cout << "1. Initialize the field data" << endl;
    cout << "2. Change the field data" << endl;
    cout << "3. Print the field data" << endl;
    cout << "4. Hit the ball" << endl;
    cout << "5. List of commands" << endl;
    cout << "6. Exit" << endl;
}

Field initializeField(){
    // Input the edges of the field while checking if they are in the right 1:2 ratio
    Point edges[4];
    Line lines[4];
    bool areEdgesValid = false;
    do{
        cout << "Enter the edges of the field: " << endl;
        for(int i = 0; i < 4; i++){
            cin >> edges[i];
        }

        lines[0] = Line(edges[0], edges[1]);
        lines[1] = Line(edges[1], edges[2]);
        lines[2] = Line(edges[2], edges[3]);
        lines[3] = Line(edges[3], edges[0]);

        if(lines[0].findLengthOfPartOfLine(edges[0], edges[1]) / lines[1].findLengthOfPartOfLine(edges[1], edges[2]) == 2){
            areEdgesValid = true;
        }
        else if(lines[1].findLengthOfPartOfLine(edges[1], edges[2]) / lines[2].findLengthOfPartOfLine(edges[2], edges[3]) == 2){
            areEdgesValid = true;
        }
        else{
            cout << "The edges are not in the right 1:2 ratio" << endl;
        }
    }
    while(!areEdgesValid);

    // Input the starting position of the ball while checking if it is in the field
    Point startingPosition;
    double diameter;
    Point innerEdges[4];
    bool isStartingPositionValid = false;
    do{
        cout << "Enter the starting position of the ball: " << endl;
        cin >> startingPosition;
        cout << "Enter the diameter of the ball: " << endl;
        cin >> diameter;

        innerEdges[0] = Point(edges[0].x + diameter / 2, edges[0].y + diameter / 2);
        innerEdges[1] = Point(edges[1].x - diameter / 2, edges[1].y + diameter / 2);
        innerEdges[2] = Point(edges[2].x - diameter / 2, edges[2].y - diameter / 2);
        innerEdges[3] = Point(edges[3].x + diameter / 2, edges[3].y - diameter / 2);

        if(startingPosition.isPointInsideRectangle(innerEdges[0], innerEdges[1], innerEdges[2], innerEdges[3])){
            isStartingPositionValid = true;
        }
        else{
            cout << "The starting position is not in the field" << endl;
        }
    }
    while(!isStartingPositionValid);

    // Create the ball
    Ball ball(startingPosition, diameter);

    // Create the field
    Field field(edges, ball);

    cout << "The field is initialized" << endl;

    return field;
}

Field changeField(){
    bool changeRunning = true;
    int option;
    Field field;

    while(changeRunning){
        cout << "Do you want to change the field:" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;

        cin >> option;

        switch(option){
            case 1:
                cout << "The field was changed" << endl;
                field = initializeField();
                break;
            case 2:
                changeRunning = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }

    return field;
}

void printField(Field field){
    field.printField();
}

void hitBall(Field* field){
    Point point;
    cout << "Enter a target point: " << endl;
    cin >> point;

    double power;
    do{
        cout << "Enter the power: " << endl;
        cin >> power;

        if(power <= 0){
            cout << "The power must be positive" << endl;
        }
    }
    while(power <= 0);

    field->hitBall(point, power);
}

void listCommands(){
    cout << "1. Initialize the field data" << endl;
    cout << "2. Change the field data" << endl;
    cout << "3. Print the field data" << endl;
    cout << "4. Hit the ball" << endl;
    cout << "5. List of commands" << endl;
    cout << "6. Exit" << endl;
}