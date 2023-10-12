#include <stdio.h>
#include <string.h>

#define SHIP_NAME_LENGTH 20
#define SHIP_MAX 100
#define SHIP_LINE_LENGTH (SHIP_NAME_LENGTH * SHIP_MAX + 101)
#define MAX_SHIP_LINES 100

int main() {

    int numShipLines;
    scanf("%d ", &numShipLines);
    
    char shipLines[MAX_SHIP_LINES][SHIP_MAX][SHIP_NAME_LENGTH + 1];
    char shipLine[SHIP_LINE_LENGTH];
    int shipLengths[MAX_SHIP_LINES];

    int numCustomers;
    int currCustomer;
    int currIndex;

    int currLineLength;
    int shipIndex;
    int charIndex;

    for(int i = 0; i < numShipLines; i++) {
        
        fgets(shipLine, SHIP_LINE_LENGTH, stdin); // takes in the whole ship line as a single string
        
        currLineLength = strlen(shipLine);
        shipIndex = 0;
        charIndex = 0;

        for(int j = 0; j < currLineLength; j++) {

            if(shipLine[j] == ' ' || shipLine[j] == '\n') { // if the loop has reached the end of one of the ship names

                shipLines[i][shipIndex][charIndex] = '\0';

                // starting the next ship name
                charIndex = 0; 
                shipIndex++;

            } else { // if the loop is still adding onto the current ship name

                shipLines[i][shipIndex][charIndex] = shipLine[j];

                charIndex++;

            }

        }

        shipLengths[i] = shipIndex; // saves the length of the current ship name

    }

    scanf("%d", &numCustomers);

    for(int i = 0; i < numCustomers; i++) { // for each customer

        scanf("%d", &currCustomer);

        for(int j = 0; j < numShipLines; j++) {
            
            currIndex = (currCustomer - 1) % shipLengths[j]; // starting at 0, loop the index through the ship line the inputed number of times 
            printf("%s", shipLines[j][currIndex]); // for each ship line, print out the ship name at the currIndex

            if(j != numShipLines - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }

    return 0;

}