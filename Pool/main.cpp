#include <iostream>

#include "table.h"

using namespace std;

void printMenu();
void initializeField();
void changeField();
void printField();
void hitBall();
void listCommands();

int main(){
    try{
        Point startingPosition(3110, 70);
        Ball ball(280, 70, 0);
        Point edges[4] = {Point(0, 0), Point(320, 0), Point(320, 160), Point(0, 160)};
    
        Table table(startingPosition, ball, edges);

        table.printTable();
    
        /*
        int option;
    
        while(true){
            printMenu();
            cin >> option;
        
            switch(option){
                case 1:
                    initializeField();
                    break;
                case 2:
                    changeField();
                    break;
                case 3:
                    printField();
                    break;
                case 4:
                    hitBall();
                    break;
                case 5:
                    listCommands();
                    break;
                case 6:
                    return 0;
                    break;
                default:
                    cout << "Invalid option" << endl;
                    break;
            }
        }
        */
    }
    catch(int e){
        cout << e << endl;
    }
    return 0;
}

void printMenu(){
    cout << "Choose an option:" << endl;
    cout << "1. Initialize the field data" << endl;
    cout << "2. Change the field data" << endl;
    cout << "3. Print the field data" << endl;
    cout << "4. Hit the ball" << endl;
    cout << "5. List of commands" << endl;
    cout << "6. Exit" << endl;
}

void initializeField(){
    cout << "Initializing the field data" << endl;
}

void changeField(){
    cout << "Changing the field data" << endl;
}

void printField(){
    cout << "Printing the field data" << endl;
}

void hitBall(){
    cout << "Hitting the ball" << endl;
}

void listCommands(){
    cout << "Listing the commands" << endl;
}
