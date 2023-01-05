#include <stdio.h>

void printMenu();
void initializeField();
void changeField();
void printField();
void hitBall();
void listCommands();

int main(){
    int option;
    
    while(true){
        printMenu();
        scanf("%d", &option);
        
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
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}

void printMenu(){
    printf("Choose an option:\n");
    printf("1. Initialize the field data\n");
    printf("2. Change the field data\n");
    printf("3. Print the field data\n");
    printf("4. Hit the ball\n");
    printf("5. List of commands\n");
    printf("6. Exit\n");
}

void initializeField(){
    printf("Initializing the field data\n");
}

void changeField(){
    printf("Changing the field data\n");
}

void printField(){
    printf("Printing the field data\n");
}

void hitBall(){
    printf("Hitting the ball\n");
}

void listCommands(){
    printf("Listing the commands\n");
}
