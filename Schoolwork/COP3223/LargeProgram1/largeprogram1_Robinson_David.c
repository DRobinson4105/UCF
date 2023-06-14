//David Robinson
//Dr. Steinberg
//COP3223 Section 1
//Large Program 1

#define ROUNDS 3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greeting(); // displays a welcome message to the user

int playRound(int round); // play a round

int humanPick(); // retrieve the user's guess

int computerPick(int choice, int leftover); // computer makes its pick

int leftOnTable(int toothpicks, int taken); // calculate the number of toothpicks left

void winnerAnnouncement(int user); // determines the winner

int main() {
    
    greeting();

    for (int x = 0; x < ROUNDS; ++x) {

        int result = playRound(x + 1); // plays a round of the toothpick game with the human

        winnerAnnouncement(result);

    }

    printf("********************************************************\n");
    printf("Thank you for playing!\n");

    return 0;

}

void greeting() {

    printf("********************************************************\n");
    printf("Welcome to Toothpick Game!\n");
    printf("Here are the rules.\n");
    printf("There are currently 31 toothpicks on the table.\n");
    printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n");
    printf("The player that gets to pick the last toothpicks loses the game!\n");
    printf("Sounds easy right? Well lets see if you can beat me!\n");
    printf("Ready to play?...Here we go!\n");
    printf("********************************************************\n");

}

int playRound(int round) {

    printf("Welcome to round %d!\n", round);
    printf("You may go first!\n");

    int toothpicks = 31; // number of toothpicks to start with

    int taken;

    while (toothpicks != 0) {

        printf("********************************************************\n");
        printf("There are %d toothpick(s) left on the table.\n", toothpicks);

        taken = humanPick();

        if (taken >= 1 && taken <= 3 && taken <= toothpicks) { // if the human takes a valid number of toothpicks

            toothpicks = leftOnTable(toothpicks, taken);
            printf("Ok... you took %d off the table.\n", taken);

        } else { // asks the human to try again if they select an invalid number of toothpicks
            
            printf("Oh no no, you can't do that in this game! Try again.\n");
            printf("********************************************************\n");
            continue;

        }

        if (toothpicks == 0) { // if the human takes the last toothpick

            return 1;

        }

        printf("I'm making my decision now.\n");

        taken = computerPick(taken, toothpicks); // computer calculates how many toothpicks it takes
        
        toothpicks = leftOnTable(toothpicks, taken); // take away amount from total toothpicks

        printf("I am taking %d toothpick(s) off the table.\n", taken);

        if (toothpicks == 0) { // if the computer takes the last toothpick
            
            return 0;

        }

        printf("********************************************************\n");
    
    }

    return 0;

}

int humanPick() {

    int toothpicks;

    printf("How many toothpicks are you going to take off the table? ");

    scanf("%d", &toothpicks); // get how many toothpicks the human will take

    return toothpicks;

}

int computerPick(int choice, int leftover) {

    if (leftover > 4) {
        
        return 4 - choice; // if there are more than 4 toothpicks left on the table
    
    } else if (leftover >= 2 && leftover <= 4) {

        return leftover - 1; // if there are 2 to 4 toothpicks left

    } else {

        return 1; // if there is 1 toothpick left on the table

    }

}

int leftOnTable(int toothpicks, int taken) {

    return toothpicks - taken;

}

void winnerAnnouncement(int user) {

    if (user == 1) { // if the computer won
            
        printf("I won! Haha better luck next time!\n");

    } else { // if the human won
            
        printf("You won! I'll let you have this one.\n");

    }

}