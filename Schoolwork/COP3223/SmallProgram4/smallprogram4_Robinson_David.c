//David Robinson
//Dr. Steinberg
//COP3223C Section 1
//Small Program 4

#include <stdio.h>
#include <stdlib.h>

void perfectSquare();

void elevator();

void pyramid();

double classAvg(int students);

int main() {

    // Problem 1 - Perfect Square

    perfectSquare();

    // Problem 2 - Elevator Ride

    elevator();

    // Problem 3 - Pyramid

    pyramid();

    // Problem 4 - Class Average

    int students = 0;
    double classAverage;
    
    while (students <= 0) { // Get the number of students and make sure that it is a positive number

        printf("How many students are in the class: ");
        scanf("%d", &students);

        if (students <= 0)
            printf("Invalid input. Please try again.\n");

    }

    classAverage = classAvg(students); // Calculate the class average for the exam

    printf("The class average on the field trip exam was a %0.4lf%%\n", classAverage);

}

void perfectSquare() {

    int squareSize = 0;

    while(squareSize <= 0) { // Keep asking for the square size until the number is positive
        
        printf("How big would you like the square to be?: ");
        scanf("%d", &squareSize);

        if(squareSize <= 0) // If the square size is not a positive number then try again
            printf("Invalid Input. Please try again.\n");

    }

    for(int i = 0; i < squareSize; i++) { printf("*"); } // Print the top side of the square

    printf("\n");

    for(int i = 0; i < squareSize - 2; i++) { // Print the left and right sides of the square

        printf("*");

        for(int i = 0; i < squareSize - 2; i++) { printf(" "); }

        printf("*\n");

    }

    for(int i = 0; i < squareSize; i++) { printf("*"); } // Print the bottom side of the square
    
    printf("\n");

}

void elevator() {

    printf("Welcome to the Elevator Ride.\n"); // Greet the user

    int floor = 1;

    while(floor != 5) { // Keep asking which floor the user wants to go to until they get to the fifth floor
        
        printf("Which floor would you like to go to? ");
        scanf("%d", &floor);

        switch(floor) { // Display a message based on the floor the user chose

            case 1:
                printf("Welcome to the first floor.\n");
                break;
            
            case 2:
                printf("Welcome to the second floor.\n");
                break;

            case 3:
                printf("Welcome to the third floor.\n");
                break;

            case 4:
                printf("Welcome to the fourth floor.\n");
                break;

            case 5:
                printf("Elevator door is now open. Please exit now.\n");
                break;

            case 6:
                printf("Welcome to the sixth floor.\n");
                break;

            case 7:
                printf("Welcome to the seventh floor.\n");
                break;

            case 8:
                printf("Welcome to the eighth floor.\n");
                break;

            case 9:
                printf("Welcome to the ninth floor.\n");
                break;

            case 10:
                printf("Welcome to the tenth floor.\n");
                break;

            case 11:
                printf("Welcome to the eleventh floor.\n");
                break;

            case 12:
                printf("Welcome to the twelfth floor.\n");
                break;

            default:
                printf("That is not a valid option.\n");
                break;

        }

    }

}

void pyramid() {

    int pyramidSteps = 0;

    while (pyramidSteps <= 0) { // Get the number of pyramid steps and make sure that it is a positive number

        printf("How many steps would you like in the pyramid? ");
        scanf("%d", &pyramidSteps);

        if(pyramidSteps <= 0)
            printf("Invalid Input. Please try again.\n");

    }

    for (int i = 1; i < pyramidSteps * 2; i++) {

        for (int j = 0; j < pyramidSteps - abs(pyramidSteps - i); j++) { printf("-"); } // Print the pyramid steps

        printf("\n");

    }

}

double classAvg(int students) {

    double totalScore = 0;
    double currentStudent = -1;
    double average;

    for (int i = 0; i < students; i++) {

        currentStudent = -1;

        while (currentStudent < 0 || currentStudent > 100) { // Make sure that each score is a number between 0 and 100 inclusive

            printf("Enter the student's test score: ");
            scanf("%lf", &currentStudent);

            if (currentStudent < 0 || currentStudent > 100)
                printf("Invalid Student Score. Please try again.\n");

        }

        totalScore += currentStudent; // Add the score to the total sum of the scores so far

    }

    average = totalScore / students; // Calculate the average score
    return average;

}