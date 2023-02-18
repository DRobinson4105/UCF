#include <stdio.h>
#include <stdlib.h>

void swap(int * x, int * y);

void quickSort(int * array, int low, int high);

int partition(int * array, int low, int high);

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    quickSort(array, 0, size - 1);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void swap(int * x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int * array, int low, int high)
{
    int pivot = array[low]; // pivot
    int i = low; 
                 
    for (int j = low + 1; j <= high; j++) {
        // If current element is smaller than the pivot
        if (array[j] < pivot) {
            i++; // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i], &array[low]);
    return i;
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}