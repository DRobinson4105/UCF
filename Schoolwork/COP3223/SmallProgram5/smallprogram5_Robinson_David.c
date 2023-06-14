// David Robinson
// Dr. Steinberg
// COP3223C Section 1
// Small Program 5

#include <stdio.h>
#include <math.h>

void change(double *amtPaid, double *amtDue);

void resterauntReceipt();

void gradeDistribution();

void incrementUpdate(int *val);

int main() {

    // Problem 1 - Change Calculator

    double amtPaid;
    double amtDue;

    printf("Amount Due: ");
    scanf("%lf", &amtDue);

    printf("Amount Paid: ");
    scanf("%lf", &amtPaid);

    change(&amtPaid, &amtDue);

    // Problem 2 - Restaurant Receipt

    resterauntReceipt();

    // Problem 3 - Grade Distribution

    gradeDistribution();

    // Problem 4 - Increment Update

    int val = 0;
    
    printf("Before calling incrementUpdate\n");
    printf("val = %d\n", val); // initial value for val

    incrementUpdate(&val);

    printf("After calling incrementUpdate\n");
    printf("val = %d\n", val); // final value for val

}

void change(double *amtPaid, double *amtDue) {

    int change;
    int dollars;
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    change = round(*amtPaid * 100) - round(*amtDue * 100); // start with the total amount of change in cents

    dollars = (change - change % 100) / 100; // see how many dollars can be used for change
    change -= dollars * 100; // take that amount from the change

    quarters = (change - change % 25) / 25; // see how many quarters can be used for change
    change -= quarters * 25; // take that amount from the change

    dimes = (change - change % 10) / 10; // see how many dimes can be used for change
    change -= dimes * 10; // take that amount from the change

    nickels = (change - change % 5) / 5; // see how many nickels can be used for change
    change -= nickels * 5; // take that amount from the change

    pennies = change; // leftover change as pennies

    printf("Change\n");
    printf("%d dollars\n", dollars);
    printf("%d quarters\n", quarters);
    printf("%d dimes\n", dimes);
    printf("%d nickels\n", nickels);
    printf("%d pennies\n", pennies);

}

void resterauntReceipt() {

    int option = -1;
    int regularCount = 0;
    int specialCount = 0;
    int cheeseCount = 0;
    int friesCount = 0;
    int saladCount = 0;
    int softDrinkCount = 0;
    double total = 0;

    FILE *receipt = fopen("myreceipt.txt", "w");

    printf("Welcome to Bob's Burgers! Our burger of the day is Say Cheese Burger!\n");

    while (option != 0) {

        printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
        printf("-----------------------\n");
        printf("1: Regular	$5.00\n");
        printf("2: Special	$5.95\n");
        printf("3: Cheese	$5.50\n");
        printf("4: Fries	$2.00\n");
        printf("5: Salad	$2.50\n");
        printf("6: Soft Drink	$2.00\n");
        printf("-----------------------\n");
        printf("What will you add to your order: ");

        scanf("%d", &option);

        switch (option) {

            case 1: // if regular is chosen
                printf("Adding regular to your order.\n");
                regularCount += 1;
                total += 5;
                break;

            case 2: // if special is chosen
                printf("Adding special to your order.\n");
                specialCount += 1;
                total += 5.95;
                break;

            case 3: // if cheese is chosen
                printf("Adding cheese to your order.\n");
                cheeseCount += 1;
                total += 5.5;
                break;

            case 4: // if fries are chosen
                printf("Adding fries to your order.\n");
                friesCount += 1;
                total += 2;
                break;
            
            case 5: // if salad is chosen
                printf("Adding salad to your order.\n");
                saladCount += 1;
                total += 2.5;
                break;

            case 6: // if soft drink is chosen
                printf("Adding soft drink to your order.\n");
                softDrinkCount += 1;
                total += 2;
                break;

            default:
                printf("Order is now placed. Printing receipt.\n");
                break;

        }

    }

    fprintf(receipt, "Bob's Burgers Restaurant Receipt Order\n");
    fprintf(receipt, "-----------------------\n");
    fprintf(receipt, "%d Regular(s)\n", regularCount);
    fprintf(receipt, "%d Special(s)\n", specialCount);
    fprintf(receipt, "%d Cheese(s)\n", cheeseCount);
    fprintf(receipt, "%d Fries\n", friesCount);
    fprintf(receipt, "%d Salad(s)\n", saladCount);
    fprintf(receipt, "%d Soft Drink(s)\n", softDrinkCount);
    fprintf(receipt, "-----------------------\n");
    fprintf(receipt, "Total: $%0.2lf\n", total);
    fprintf(receipt, "Thank you and come again!");

    fclose(receipt);

}

void gradeDistribution() {

    int numOfA = 0;
    int numOfB = 0;
    int numOfC = 0;
    int numOfD = 0;
    int numOfF = 0;
    char currentChar[200];

    FILE *grades = fopen("grades.txt", "r");
    
    while (fgets(currentChar, 200, grades) != NULL) {

        switch(currentChar[0]) { // increment the count for whatever grade is on the current line

            case 'A':
                numOfA += 1;
                break;

            case 'B':
                numOfB += 1;
                break;
            
            case 'C':
                numOfC += 1;
                break;
            
            case 'D':
                numOfD += 1;
                break;

            case 'F':
                numOfF += 1;
                break;

            default:
                break;

        }
        
    }

    fclose(grades);

    printf("Here is the grade distribution.\n");
    printf("A: %d\n", numOfA);
    printf("B: %d\n", numOfB);
    printf("C: %d\n", numOfC);
    printf("D: %d\n", numOfD);
    printf("F: %d\n", numOfF);

}

void incrementUpdate(int *val) {

    int option = 0;

    while (option == 0) {

        printf("Updating val now...\n");

        *val += 1; // increment val

        printf("Would you like to update ...\n");
        printf("Enter 0 if you would like to update again. Anything else will exit the update.\n");
        printf("Option: ");

        scanf("%d", &option);

    }

    printf("val is now done updating...\n");

}