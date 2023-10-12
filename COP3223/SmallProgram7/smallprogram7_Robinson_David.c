//David Robinson
//Dr. Steinberg
//COP3223C Section 1
//Small Program 7

#define SIZE 20
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deblank(char input[], char output[]);

void pluralize(char word[]);

void fact(char string[]);

char* substring(char string1[], char string2[]);

int main()
{
    // Problem 1 - Deblank

    char input[SIZE];
    char output[SIZE];

    printf("Enter a string: ");
    scanf("%[^\n]", input);

    deblank(input, output);

    printf("Output String with no blanks: %s\n", output);

    // Problem 2 - Pluralize

    char word[SIZE];

    printf("Enter string to be pluralize: ");
    scanf("%s", word);

    pluralize(word);

    printf("Word pluralize: %s\n", word);

    // Problem 3 - Fact

    char string[SIZE];

    printf("Enter a string with no spaces: ");
    scanf("%s", string);

    fact(string);

    // Problem 4 - Substring

    char totalString[SIZE];
    char subString[SIZE];
    char *substringAddress;

    printf("Enter the string: ");
    scanf(" %s", totalString);

    printf("Enter the substring you would like to look for: ");
    scanf(" %s", subString);

    substringAddress = substring(totalString, subString);
    if(substringAddress != NULL)
        printf("Substring %s exists!\n", subString);
    else
        printf("Substring %s doesn't exist!\n", subString);
}

void deblank(char input[], char output[])
{
    int currentIndex = 0;

    for(int i = 0; i < SIZE; i++)
    {
        if(input[i] != ' ') // add the current char from input to output if it is not blank
        {
            output[currentIndex] = input[i];
            currentIndex++;
        }
    }
}

void pluralize(char word[])
{
    if(word[strlen(word) - 1] == 'y') // if the word ends with "y" then replace it with "ies"
    {
        word[strlen(word) - 1] = '\0';
        strcat(word, "ies");    
    }
    else if(word[strlen(word) - 1] == 's' || (word[strlen(word) - 2] == 'c' && word[strlen(word) - 1] == 'h') || (word[strlen(word) - 2] == 's' && word[strlen(word) - 1] == 'h')) // if the word ends in "s", "ch", or "sh" then add "es"
    {
        strcat(word, "es");
    }
    else // in all other cases, add "s"
    {
        strcat(word, "s");
    }
}

void fact(char string[])
{
    int numLetters = 0;
    int numDigits = 0;
    int numPunctuation = 0;
    
    for(int i = 0; i < strlen(string); i++)
    {
        if(isalpha(string[i])) // if the current character is a letter
            numLetters++;
        else if(isdigit(string[i])) // if the currect character is a digit
            numDigits++;
        else // if the current character is a punctuation
            numPunctuation++;

    }

    printf("%s has\n", string);
    printf("%d letters\n", numLetters);
    printf("%d digits\n", numDigits);
    printf("%d punctuation characters\n", numPunctuation);
}

char* substring(char string1[], char string2[])
{   
    int exists = 1;
    for(int i = 0; i <= strlen(string1) - strlen(string2); i++) // loop through every possible starting index of the substring
    {   
        exists = 1;

        for(int j = 0; j < strlen(string2); j++)
        {
            if(string1[i + j] != string2[j]) // if a character in the substring does not match up with the character in the big string then the substring does not exist with a starting index of i
                exists = 0;
        }

        if(exists)
            return &string1[i]; // return the memory address of the starting character if found where the substring exists

    }

    return NULL; // if the substring does not exist in the larger string
}