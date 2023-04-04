#include <stdio.h>
#include <stdlib.h>

// Runtime:
// - Best: O(NlogN)
// - Average: O(NlogN)
// - Worst: O(N^2)

// Swap values that num1 and num2 point to
void swap(int * num1, int * num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Use array[low] as pivot point and put all values
// less than the pivot point to the left of it and 
// all values greater than it to the right of it
// Return the new pivot point index
// array[] --> Array to be sorted
// low --> Starting index
// high --> Ending index
int partition(int * array, int low, int high)
{
    int pivot = array[low]; // First element as pivot
    int i = low; // Location for pivot point

    // Traverse each element of the array and compare with pivot
    for (int j = low + 1; j <= high; j++)
    {    
        // If current element smaller than pivot is found, swap it with current location for pivot
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // Swap the lowest value with the new pivot location
    swap(&array[i], &array[low]);
    
    // Return the index for the pivot point
    return i;
}

// Use the first value in an array as a pivot point,
// putting all values less than it to the left and all
// values greater than it to the right
// Repeat process on subarrays of the values to the
// left and right of the pivot point until the subarray
// doesn't have any values
// array[] --> Array to be sorted
// low --> Starting index
// high --> Ending index
void quickSort(int * array, int low, int high)
{
    if (low < high)
    {     
        // Sets pivot point in right place, partioning the smaller and larger values
        int pivot = partition(array, low, high);
 
        // Separately sort elements before pivot and after pivot
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

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