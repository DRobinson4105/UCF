//David Robinson
//Dr. Steinberg
//COP3223 Section 1
//Large Program 2

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void greeting(); // welcome the user

void order(double *balance); // user will make a purchase

void viewHand(double *balance); // display current amount in hand

void transaction(double *balance, double price); // transaction with user

void pullMoney(double *balance); // grab more money from the unlimited wallet

void displayVendingOptions(); // display beverage options and prices

int main() {

    greeting();

    double balance = 0;
    double *balancePtr = &balance;

    char option = 'A';

    while(tolower(option) != 'e') {

        printf("**************************************************\n");
        printf("Please select one of the following options.\n");
        printf("O: Order from the unlimited vending machine.\n");
        printf("V: View what you have in your hand currently.\n");
        printf("D: Display what the unlimited vending machine contains.\n");
        printf("G: Grab money out of unlimited wallet.\n");
        printf("E: Exit\n");
        printf("**************************************************\n");
        printf("Please select what you would like to do.\n");
        printf("Option Selected: ");

        scanf(" %c", &option);

        printf("\n");

        switch (tolower(option)) {
            case 'e': // Exit
                printf("**************************************************\n");
                printf("Thank you for visiting the unlimited vending machine!\n");
                printf("You have $%0.2lf in your hand. Make sure to put that back into your unlimited wallet.\n", balance);
                printf("Have a great day!\n");
                break;

            case 'd': // Display what the unlimited vending machine contains
                printf("You selected the view vending machine option.\n");
                displayVendingOptions();
                break;
            
            case 'v': // View what you have in your hand currently
                printf("You selected to see how much cash you have in your hand currently.\n");
                viewHand(balancePtr);
                break;

            case 'g': // Grab money out of unlimited wallet
                pullMoney(balancePtr);
                break;

            case 'o': // Order from the unlimited vending machine
                printf("You have selected to order something from the unlimited vending machine.\n");
                order(balancePtr);
                break;

            default: // If invalid option was selected
                printf("Sorry! That option is not recognized. Please try again.\n");
                break;
            
        }

    }
    

    return 0;

}

void greeting() {

    printf("Welcome to the Unlimited Vending Machine\n"); // greet the user
    printf("We have an unlimited variety of drinks\n");
    printf("With your unlimited wallet, you will never run out of cash!\n");
    printf("What would you like to order today?\n");

}

void order(double *balance) {

    int option = 0;
    double price;

    printf("**************************************************\n");
    displayVendingOptions();

        
    printf("What would you like today?\n");
    printf("Option Selected: ");
    scanf("%d", &option);

    switch (option) {

        case 1: // Sprite
            price = 2.50;
            printf("Sprite has been selected. Total cost is: $2.50\n");
            break;

        case 2: // Coca-Cola
            price = 2.50;
            printf("Coca-Cola has been selected. Total cost is: $2.50\n");
            break;

        case 3: // Water
            price = 2.00;
            printf("Water has been selected. Total cost is: $2.00\n");
            break;

        case 4: // Gatorade
            price = 3.00;
            printf("Gatorade has been selected. Total cost is: $3.00\n");
            break;

        case 5: // Diet Cola
            price = 2.55;
            printf("Diet Cola has been selected. Total cost is: $2.55\n");
            break;

        case 6: // Fanta
            price = 2.55;
            printf("Fanta has been selected. Total cost is: $2.55\n");
            break;

        case 7: // Root Beer
            price = 1.50;
            printf("Root Beer has been selected. Total cost is: $1.50\n");
            break;

        case 8: // Dr. Pepper
            price = 1.55;
            printf("Dr. Pepper has been selected. Total cost is: $1.55\n");
            break;

        default: // If invalid option is selected
            printf("Sorry, that is not one of the options recognized.\n");

    }
    
    if (option >= 1 && option <= 8) // Make transaction if valid option is selected
        transaction(balance, price);
    else
        printf("**************************************************\n");

}

void viewHand(double *balance) {

    printf("**************************************************\n");
    printf("You have $%0.2lf in your hand currently.\n", *balance); // display acount balance
    printf("**************************************************\n");

}

void transaction(double *balance, double price) {

    printf("Beginning Transaction Process.\n");

    while (price > *balance) { // If the user does not have enough money in hand to purchase that beverage

        printf("You do not have enough in your account.\n");
        printf("Please pull more money from the unlimited wallet.\n");
        pullMoney(balance);

    }

    printf("You have $%0.2lf in your hand before transaction.\n", *balance);
    printf("Putting $%0.2lf into the vending machine.\n", price);

    *balance -= price; // Take the money for the beverage cost from the user's hand

    printf("Transaction was successful!\n");
    printf("You have now $%0.2lf in your hand.\n", *balance);
    printf("**************************************************\n");

}

void pullMoney(double *balance) {

    int option = 0;
    double moneyPulled;
    
    printf("**************************************************\n");

    while (option < 1 || option > 3) { // Make sure that the user either pulls $1, $5, or $10 from their wallet

        printf("How much would you like to pull from the unlimited wallet?\n");
        printf("1: $1.00\n");
        printf("2: $5.00\n");
        printf("3: $10.00\n");
        printf("Option Selected: ");
        scanf("%d", &option);
        
        switch(option) {
            
            case 1: // If $1.00 is selected
                moneyPulled = 1;
                break;

            case 2: // If $5.00 is selected
                moneyPulled = 5;
                break;

            case 3: // If $10.00 is selected
                moneyPulled = 10;
                break;

            default: // If an invalid option is selected
                printf("Sorry, that is not one of the options recognized.\n");
                break;

        }

    }
    
    *balance += moneyPulled; // Add the money pulled from the wallet to the user's hand

    printf("**************************************************\n");
    printf("$%0.2lf has been added to your hand successfully!\n", moneyPulled); // Display how much money the user pulled and the new account balance
    printf("**************************************************\n");

}

void displayVendingOptions() {

    printf("Here are the options!\n");
    printf("**************************************************\n");
    printf("1. Sprite        $2.50\n");
    printf("2. Coca-Cola     $2.50\n");
    printf("3. Water         $2.00\n");
    printf("4. Gatorade      $3.00\n");
    printf("5. Diet Cola     $2.55\n");
    printf("6. Fanta         $2.55\n");
    printf("7. Root Beer     $1.50\n");
    printf("8. Dr. Pepper    $1.55\n");
    printf("**************************************************\n");

}