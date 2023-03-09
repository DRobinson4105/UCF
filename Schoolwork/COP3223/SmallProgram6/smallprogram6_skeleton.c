//Small Program 6 Skeleton
//Dr. Steinberg
//COP3323C Fall 2022

#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

void display(int arr[]);

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
	
	return 0;
}

void display(int arr[])
{
	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");
}