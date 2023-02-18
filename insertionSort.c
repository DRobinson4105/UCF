#include <stdio.h>
#include <stdlib.h>

void insertionSort(int * array, int size, int curr);

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    insertionSort(array, size, 1);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}

void insertionSort(int * array, int size, int curr)
{
    if(curr == size) return;
    
    int temp;

    for(int i = 0; i < curr; i++) 
    {
        if(array[curr] < array[i])
        {
            for(int j = i; j < curr; j++)
            {
                temp = array[j];
                array[j] = array[curr];
                array[curr] = temp;
            }
        }
    }
    
    insertionSort(array, size, curr + 1);
}