//David Robinson
//Dr. Steinberg
//COP3223 Section 1
//Large Program 3

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRIKES 6
#define MAXSIZE 20

void rules();

void maskWord(char starword[], int size);

int playRound(char starword[], char answer[]);

int occurancesInWord(char userguess, char answer[]);

void updateStarWord(char starword[], char answer[], char userguess);

void playAgain(int *play);

int main()
{
    FILE *words = fopen("words.txt", "r");

    int play = 1;

    char currWord[MAXSIZE];
    char starWord[MAXSIZE];

    printf("Welcome to the Hangman Game!\n");
    
    rules();

    fscanf(words, "%s ", currWord); // first word

    while(play == 1)
    {

        maskWord(starWord, strlen(currWord)); // mask the current word in the starWord string

        playRound(starWord, currWord); // play next round

        if(fscanf(words, "%s ", currWord) == -1) // user reached the end of the game
        {
            printf("You have reached the end of the game.\n\n");
            break;
        } 
        
        playAgain(&play); // asks the user if they want to play again
    }

    printf("Thank you for playing today!\n");

    fclose(words);

    return 0;
}

void rules()
{
    printf("************************************************************************\n");
    printf("Here are the rules.\n");
    printf("I will provide you a set of * characters for each round.\n");
    printf("Each * represents a letter in the English Alphabet.\n");
    printf("You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
    printf("Are you ready? Here we go!\n");
    printf("************************************************************************\n");
}

void maskWord(char starword[], int size)
{
    for(int i = 0; i < size; i++) // adds a star for every character in the word
        starword[i] = '*';
    
    starword[size] = '\0'; // makes sure there are no more characters
}

int playRound(char starword[], char answer[])
{
    int currStrikes = 0;
    char guess;
    int occurances;
    char guesses[26] = {'\0'};
    int currGuess = 0;
    int alreadyUsed;
    int size = strlen(answer);

    printf("Welcome to the Round!\n");
    printf("The size of the word has %d letters.\n", size);

    while(currStrikes < STRIKES) // asks guesses until the user guesses the whole word or the user has 6 stroles
    {
        printf("\nYou currently have %d strike(s).\n", currStrikes); // displays current amount of strikes
        printf("Letter(s) you have guessed: %s\n\n", guesses); // displays all of the letters already guessed
        printf("%s\n\n", starword);

        printf("Enter your guess: ");
        scanf(" %c", &guess);
        printf("\n");

        guess = tolower(guess);

        if(!isalpha(guess)) // retry guess if the guess is not a letter
        {
            printf("You did not enter a letter from the alphabet.\n");
            continue;
        }

        alreadyUsed = 0;

        for(int i = 0; i < strlen(guesses); i++)
        {
            if(guesses[i] == guess) // if the user already guessed the letter
            {
                printf("You have already picked that letter\n");
                alreadyUsed = 1;
                break;
            }
        }

        if(alreadyUsed) // ask for another guess if letter was already picked
            continue;
        
        updateStarWord(starword, answer, guess); // update the masked word with any correctly guessed letters

        if(strcmp(starword, answer) == 0) // if the whole masked word has been revealed and every letter in it has been guessed
        {
            printf("Congratulations! You won! The word was %s.\n", answer);
            return 1;
        }

        occurances = occurancesInWord(guess, answer);

        if(occurances > 0)
        {
            printf("The letter %c is in the word.\n", guess);
        }
        else
        {
            printf("The letter %c is NOT in the word.\n", guess);
            
            currStrikes++;
        }

        guesses[currGuess] = guess; // adds the guess to the already guessed letters
        currGuess++;
    }

    printf("************************************************************************\n");
    printf("Sorry you did not win the round. The word was %s.\n", answer);
    
    return 0;
}   

int occurancesInWord(char userguess, char answer[])
{
    int count = 0;

    for(int i = 0; i < strlen(answer); i++)
    {
        if(answer[i] == userguess) // add one to the count whenever the guess is in the answer
            count++;
    }

    return count;
}

void updateStarWord(char starword[], char answer[], char userguess)
{
    for(int i = 0; i < strlen(answer); i++)
    {
        if(answer[i] == userguess) // if the guessed character is in the answer at that index then reveal it in the masked word
            starword[i] = answer[i];
    }
}

void playAgain(int *play)
{
    int option = 0;

    printf("************************************************************************\n");
    
    while(option != 1 && option != 2) // keeps asking until the user picks a valid option
    {
        printf("Would you like to play another round?\n");
        printf("1: Yes\n");
        printf("2: No\n");
        
        printf("Choice: ");
        scanf("%d", &option);
        printf("\n");

        if(option != 1 && option != 2) // if the user does not pick a valid option
            printf("That is not a valid option\n");

    }

    printf("************************************************************************\n");

    *play = option;
}