#include <stdio.h>
#include <stdlib.h>

// Runtime:
// - Best: O(NlogN)
// - Average: O(NlogN)
// - Worst: O(NlogN)

// Repeatedly splits array until each subarray has a 
// length of one and then merges and sorts the subarrays
// array[] --> Array to be sorted
// L --> Starting index
// R --> Ending index
void mergeSort(int * array, int L, int R);

// Merges and sorts two subarrays of elements where 
// first subarray is array[L..M] and second subarray 
// is array[M+1..R]
// array[] --> Array to be sorted
// L --> Starting index
// R --> Ending index
// M --> Midpoint between L and R
void merge(int * array, int L, int R, int M);

int main()
{
    int size;
    int * array;

    scanf("%d", &size);

    array = (int *) malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    mergeSort(array, 0, size - 1);

    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void merge(int * array, int L, int R, int M)
{
    int length1 = M - L + 1;
    int length2 = R - M;

    // Create temp arrays for left and right subarrays
    int * arrL = (int *) malloc(sizeof(int) * length1);
    int * arrR = (int *) malloc(sizeof(int) * length2);

    // Copy left and right subarray elements into temp arrays
    for(int i = 0; i < length1; i++)
        arrL[i] = array[i + L];

    for(int i = 0; i < length2; i++)
        arrR[i] = array[M + 1 + i];

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = L; // Initial index of merged subarray
    
    // Merge temp arrays back into array[L..R]
    while (i < length1 && j < length2)
    {
        // If arrL[i] is less than or equal to arrR[j] then add arrL[i] to the 
        // next index in the merged subarray and move to the next value in arrL[]
        if (arrL[i] <= arrR[j])
        {
            array[k] = arrL[i];
            i++;
        }
        else
        {
            array[k] = arrR[j];
            j++;
        }
        
        k++;
    }
    
    // Copy any remaining elements in arrL[]
    while (i < length1)
    {
        array[k] = arrL[i];
        i++;
        k++;
    }
 
    // Copy any remaining elements in arrR[]
    while (j < length2)
    {
        array[k] = arrR[j];
        j++;
        k++;
    }

    // Free temp arrays
    free(arrL);
    free(arrR);
}

void mergeSort(int * array, int L, int R)
{
    if(L < R)
    {
        int M = L + (R - L) / 2;

        // Sort left and right halves of array
        mergeSort(array, L, M);
        mergeSort(array, M + 1, R);

        // Merge both halves together
        merge(array, L, R, M);
    }
}
