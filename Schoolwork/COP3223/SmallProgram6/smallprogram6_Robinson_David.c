// David Robinson
// Dr. Steinberg
// COP3223C Section 1
// Small Program 6

#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

void display(int arr[]);

void meanMinMax(int arr[]);

void mySort(int arr[]);

void doubleShift(int arr[]);

void reverse(int arr[]);

int main(void)
{
	int arr[SIZE];
	int seed;
	printf("Enter a seed: ");
	
	scanf("%d", &seed);
	srand(seed);
	
	//generate numbers for the array
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1; //1-1000
	}
	
	//call your functions for small program 6
	
    // Problem 1 - Mean Min Max
    
    meanMinMax(arr);

    // Problem 2 - Array Sort

    mySort(arr);

    display(arr);

    // Problem 3 - Double Shift

    doubleShift(arr);

    display(arr);

    // Problem 4 - Reverse

    reverse(arr);

    display(arr);
    
	return 0;
}

void display(int arr[])
{
	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");
}

void meanMinMax(int arr[])
{
    double total = 0;
    double avg;
    int min = SIZE;
    int max = 1;

    for (int i = 0; i < SIZE; i += 1)
    {
        total += arr[i];

        if (arr[i] < min) // if the current number is lower than the current min number then replace it with the current number
            min = arr[i]; 

        if (arr[i] > max) // if the current number is higher than the current max number then replace it with the current number
            max = arr[i];
    }
  
    avg = total / SIZE; // calculate average by dividing the sum of the 

    printf("Average: %0.6lf\n", avg); // prints average value
    printf("Max: %d\n", max); // prints highest value
    printf("Min: %d\n\n", min); // prints lowest value

}

void mySort(int arr[])
{
    int lowest = SIZE;
    int index;
    int newarr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {   
        lowest = 1000;

        for (int j = 0; j < SIZE; j++)
        {
            if (arr[j] < lowest) // finds lowest value
            {
                lowest = arr[j]; // saves lowest value
                index = j; // saves the index of the lowest value
            }

        }

        arr[index] = SIZE + 1; // replaces the lowest value in the array with a number that won't be checked again
        newarr[i] = lowest; // saves that as the next lowest value in the new array
    }

    for (int a = 0; a < SIZE; a++)
    {
        arr[a] = newarr[a]; // replaces all of the values from the new ascending array to the inputed array
    }

}

void doubleShift(int arr[])
{
    int newarr[SIZE];

    for (int i = 2; i < SIZE; i++)  // starting with the third number, save the value from 2 indexes earlier
    {
        newarr[i] = arr[i - 2];
    }

    newarr[0] = arr[SIZE - 2]; // save the second to last value to the first number of the new array
    newarr[1] = arr[SIZE - 1]; // save the last value to the second number of the new array

    for (int a = 0; a < SIZE; a++) 
    {
        arr[a] = newarr[a]; // replaces all of the values from the new shifted array to the inputed array
    }

}

void reverse(int arr[])
{
    int num;

    for (int i = 0; i < (double)(SIZE / 2); i++) // swap the values for each set of numbers (0 & 999, 1 & 998) all the way to the middle of the array
    {
        num = arr[i];
        arr[i] = arr[SIZE - i - 1];
        arr[SIZE - i - 1] = num;
    }

}