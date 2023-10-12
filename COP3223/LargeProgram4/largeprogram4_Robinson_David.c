//David Robinson
//Dr. Steinberg
//COP3223 Section 1
//Large Program 4

#define MAX 30
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct pirate {
    char name[MAX];
    int age;
    char crew[MAX];
    char devilFruit[MAX];
} pirate;

void greeting(); // greet the user and explain how the record manager works

void addPirate(pirate records[], int recordSize, char name[], int age, char crew[], char devilFruit[]); // add a new pirate with a name, age, crew, and devil fruit

void removePirate(pirate records[], int recordSize, int index); // remove an existing pirate at that index

int locatePirate(pirate records[], int recordSize, char name[]); // locate an existing pirate with that name

void displayPirate(pirate records[], int ID); // show a list of all pirate records

void printList(pirate records[], int recordSize); // print all pirate records to the text file

int main()
{
    pirate records[MAX];
    int recordSize = 6;

    char wholeOption[MAX];
    char option = 'a';
    char tempName[MAX];
    char tempAge[MAX];
    int num;
    char tempCrew[MAX];
    char tempDevilFruit[MAX];
    int index;

    greeting();

    // Adds the Hardcore Six records that the program starts with
    addPirate(records, 0, "Luffy", 19, "Straw Hat Pirates", "Gum-Gum");
    addPirate(records, 1, "Zoro", 21, "Straw Hat Pirates", "None");
    addPirate(records, 2, "Law", 26, "The Heart Pirates", "Op-Op");
    addPirate(records, 3, "Arlong", 41, "Arlong Pirates", "None");
    addPirate(records, 4, "Bon Clay", 32, "Baroque Works", "Clone-Clone");
    addPirate(records, 5, "Doflamingo", 41, "Donquixote Pirates", "String-String");

    while(tolower(option) != 'c')
    {
        printf("**************************************************\n");
        printf("Please select one of the following options\n");
        printf("A: Add a new pirate record \n");
        printf("R: Remove an existing pirate record \n");
        printf("L: Locate an existing pirate record\n");
        printf("D: Display a list of all pirate records\n");
        printf("C: Close the Pirate Record Manager\n");
        printf("**************************************************\n");
        printf("Please select what you would like to do.\n");
        printf("Option Selected: ");

        scanf(" %[^\n]", wholeOption);

        printf("\n");

        if(wholeOption[1] != '\0')
        {
            printf("That is not an available option.\n");
            continue;
        }

        option = wholeOption[0];

        switch(tolower(option))
        {
            case 'a': // if the user wants to add a pirate record
                
                if(recordSize == 30)
                {
                    printf("You have reached the max limit of records and can't add a new one unless an existing one is removed.\n");
                    break;
                }

                printf("You have chosen to add a new pirate.\n");
                
                printf("\nWhat is the pirate's name?\n");
                printf("Name: ");
                scanf(" %[^\n]", tempName);

                if(locatePirate(records, recordSize, tempName) != -1)
                {
                    printf("\nThat pirate already has a record.\n");
                    displayPirate(records, locatePirate(records, recordSize, tempName));
                    break;
                }

                printf("\nWhat is the pirate's age?\n");
                printf("Age: ");
                scanf(" %[^\n]", tempAge);

                num = 0;
                for(int i = 0; i < strlen(tempAge); i++) // if the user does not input a number for the age
                {
                    if(!isdigit(tempAge[i]))
                        num = 1;
                }

                while(num == 1) // keep asking until the user inputs a number for the age
                {
                    printf("Please enter a valid age\n");
                    printf("Age: ");
                    scanf(" %[^\n]", tempAge);

                    num = 0;
                    for(int i = 0; i < strlen(tempAge); i++)
                    {
                        if(!isdigit(tempAge[i]))
                            num = 1;
                    }
                }
                

                for(int i = 0; i < strlen(tempAge); i++)
                {
                    num += ((tempAge[i] - 48) * (pow(10, strlen(tempAge) - 1 - i)));
                }

                printf("\nWhat crew is the pirate in? (Examples: Straw Hat Pirates, The Heart Pirates)\n");
                printf("Crew: ");
                scanf(" %[^\n]", tempCrew);

                printf("\nWhat devil fruit does the pirate have? (Examples: Gum-Gum, Flower-Flower)\n");
                printf("Devil Fruit (Put None if the pirate does not have one): ");
                scanf(" %[^\n]", tempDevilFruit);

                addPirate(records, recordSize, tempName, num, tempCrew, tempDevilFruit); // create new pirate record with given name, age, crew, and devil fruit
                
                printf("\n%s has been added!\n", tempName); // confirms that the pirate has been added

                recordSize++; // increment the current size of the record list

                break;
            
            case 'r': // if the user wants to remove a pirate record

                printf("You have chosen to remove an existing pirate.\n");

                printf("\nWhat is the pirate's name?\n");
                printf("Name: ");
                scanf("%s", tempName);
                
                index = locatePirate(records, recordSize, tempName);
                
                if(index == -1) // if the pirate record does not exist
                {
                    printf("\nWe could not find that pirate.\n");
                }
                else // if the pirate record does exist
                {
                    removePirate(records, recordSize, index);

                    printf("\n%s has been removed!\n", tempName); // confirms that the pirate has been removed

                    recordSize--; // decrement the current size of the record list
                }

                break;

            case 'l': // if the user wants to locate a pirate record

                printf("You have chosen to locate an existing pirate.\n");
                
                printf("\nWhat is the pirate's name?\n");
                printf("Name: ");
                scanf("%s", tempName);
                printf("\n");
                
                index = locatePirate(records, recordSize, tempName); // finds the index in the record array for the requested pirate record

                if(index == -1) // if the record could not be found
                {
                    printf("We could not find that pirate.\n");
                }
                else // display the record if found
                {
                    printf("We have found the pirate you are looking for.\n");
                    displayPirate(records, index);
                }

                break;

            case 'd': // if the user wants to display all records

                printf("You have chosen to display all pirate records.\n");

                for(int i = 0; i < recordSize; i++)
                {
                    printf("------------------------------------------\n");
                    displayPirate(records, i);
                }

                break;

            case 'c': // if the user wants to close the record manager

                printf("You have chosen to close the pirate record manager.\n");

                printList(records, recordSize); // save all of the current pirate records to the text file

                printf("The records have been saved to the text file.\n");
                printf("Thank you for using the pirate record manager and have a good day!\n");

                break;

            default: // if the user chooses an invalid option

                printf("That is not an available option.\n");

                break;

        }
    }

    return 0;
}

void greeting()
{
    printf("Welcome to the One Piece Pirate Record Manager!\n");
    printf("This is where we store all of the records for pirates\n");
    printf("You are able to view existing records and add or remove pirate records\n");
}

void addPirate(pirate records[], int recordSize, char name[], int age, char crew[], char devilFruit[])
{
    strcpy(records[recordSize].name, name); // save the pirate name
    records[recordSize].age = age; // save the pirate age
    strcpy(records[recordSize].crew, crew); // save what crew the pirate is a part of
    strcpy(records[recordSize].devilFruit, devilFruit); // save what devil fruit the pirate has if they have one
}

void removePirate(pirate records[], int recordSize, int index)
{
    for(int i = index; i < recordSize; i++)
    {
        records[i] = records[i + 1];
    }
}

int locatePirate(pirate records[], int recordSize, char name[])
{
    char temp1[MAX];
    char temp2[MAX];
    for(int i = 0; i < recordSize; i++)
    {
        // Convert both name strings to lowercase so that the comparison is not case-sensitive
        for(int j = 0; j < strlen(records[i].name); j++)
            temp1[j] = tolower(records[i].name[j]);
        temp1[strlen(records[i].name)] = '\0';
        for(int j = 0; j < strlen(name); j++)
            temp2[j] = tolower(name[j]);
        temp2[strlen(name)] = '\0';

        if(strcmp(temp1, temp2) == 0) // if the record is found then return the index of it
            return i;
    }
    return -1; // return -1 if the record is not found
}

void displayPirate(pirate records[], int index)
{
    printf("ID:          %d\n", index + 1);
    printf("Name:        %s\n", records[index].name);
    printf("Age:         %d\n", records[index].age);
    printf("Crew:        %s\n", records[index].crew);
    printf("Devil Fruit: %s\n", records[index].devilFruit);
}

void printList(pirate records[], int recordSize)
{
    FILE *pF = fopen("records.txt", "w");

    fprintf(pF, "One Piece Pirates\n");
    fprintf(pF, "------------------------------------------\n");

    for(int i = 0; i < recordSize; i++) // print each record to the text file
    {
        fprintf(pF, "ID:          %d\n", i + 1);
        fprintf(pF, "Name:        %s\n", records[i].name);
        fprintf(pF, "Age:         %d\n", records[i].age);
        fprintf(pF, "Crew:        %s\n", records[i].crew);
        fprintf(pF, "Devil Fruit: %s\n", records[i].devilFruit);
        fprintf(pF, "------------------------------------------\n");
    }

    fclose(pF);

}