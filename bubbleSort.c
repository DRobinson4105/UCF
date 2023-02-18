#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * array, int size);

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    bubbleSort(array, size);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void bubbleSort(int * array, int index)
{
    int temp;

    if(index == 1) return;

    for (int j = 0; j < index - 1; j++)
    {
        if (array[j] > array[j + 1])
        {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }

    bubbleSort(array, index - 1);
}