#include <stdio.h>
#include <stdlib.h>

void selectionSort(int * array, int size, int curr);

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    selectionSort(array, size, 0);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void selectionSort(int * array, int size, int curr)
{
    if(curr == size - 1) return;

    int temp;
    int lowest;

    lowest = curr;
    for(int j = curr; j < size; j++)
        if(array[j] < array[lowest]) lowest = j;

    temp = array[curr];
    array[curr] = array[lowest];
    array[lowest] = temp;
    
    selectionSort(array, size, curr + 1);
}