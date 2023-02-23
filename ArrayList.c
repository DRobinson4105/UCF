#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList ArrayList;

struct ArrayList {
    int size, cap;
    int * array;
};

// Allocates memory for an arraylist with the starting
// capacity for the array and returns a pointer to it
ArrayList * initialize(int startingCap);

// Adds value to the end of the arraylist
void append(ArrayList * arraylist, int value);

// Removes element at given index from the arraylist
void removeFromList(ArrayList * arraylist, int index);

// Adds value to the arraylist at the given index
void insert(ArrayList * arraylist, int value, int index);

// Prints arraylist with brackets as [n1, n2, ...]
void printList(ArrayList * arraylist);

// Reverse order of elements in arraylist
void reverseList(ArrayList * arraylist);

// Repeatedly splits array until each subarray has a 
// length of one and then merges and sorts the subarrays
// L --> Starting index
// R --> Ending index
void sortList(ArrayList * arraylist, int L, int R);

// Merges and sorts two subarrays of elements where 
// first subarray is array[L..M] and second subarray 
// is array[M+1..R]
// L --> Starting index
// R --> Ending index
// M --> Midpoint between L and R
void merge(ArrayList * arraylist, int L, int R, int M);

// Swap values that num1 and num2 point to
void swap(int * num1, int * num2);

// Free memory for arraylist
void freeList(ArrayList * arraylist);

int main()
{
    ArrayList * list = initialize(10);

    // Linked List: {5, 10, 11, 7, 1, 9, 6, 2, 8, 4}
    //     Indexes:  0   1   2  3  4  5  6  7  8  9
    append(list, 5);
    append(list, 10);
    append(list, 11);
    append(list, 7);
    append(list, 1);
    append(list, 9);
    append(list, 6);
    append(list, 2);
    append(list, 8);
    append(list, 4);

    printList(list);

    // Remove element at index of 2 in the arraylist which is 11
    // ArrayList: {5, 10, 7, 1, 9, 6, 2, 8, 4}
    //     Indexes:  0   1  2  3  4  5  6  7  8
    removeFromList(list, 2);
    printList(list);

    // Insert 3 at the index of 5 so it is between 9 and 6
    // ArrayList: {5, 10, 7, 1, 9, 3, 6, 2, 8, 4}
    //     Indexes:  0   1  2  3  4  5  6  7  8  9
    insert(list, 3, 5);
    printList(list);

    // Size: 10
    printf("Size: %d\n", list->size);

    // Reversed order of elements
    // ArrayList: {4, 8, 2, 6, 3, 9, 1, 7, 10, 5}
    //     Indexes:  0  1  2  3  4  5  6  7   8  9
    reverseList(list);
    printList(list);

    // Sort arraylist
    // ArrayList: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    //     Indexes:  0  1  2  3  4  5  6  7  8   9
    sortList(list, 0, list->size - 1);
    printList(list);

    // Get value at 4th index of arraylist which is 5
    // ArrayList: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    //     Indexes:  0  1  2  3 (4)  5  6  7  8   9
    printf("list[4] = %d\n", list->array[4]);

    // Free arraylist from memory
    freeList(list);

    return 0;
}

ArrayList * initialize(int startingCap)
{
    // Allocate memory for list
    ArrayList * newList = (ArrayList *) malloc(sizeof(ArrayList));

    // Initialize all parts of struct
    newList->cap = startingCap;
    newList->size = 0;
    newList->array = (int *) malloc(sizeof(int) * startingCap);

    return newList;
}

void append(ArrayList * arraylist, int value)
{
    // Check if array is full and double capacity if so
    if(arraylist->size == arraylist->cap)
    {
        arraylist->cap *= 2;
        arraylist->array = realloc(arraylist->array, arraylist->cap);
    }

    // Add value to the end
    arraylist->array[arraylist->size] = value;
    arraylist->size++;
}

void removeFromList(ArrayList * arraylist, int index)
{
    // Shifts all elements to the right of array[index] to the left by one
    for(int i = index; i < arraylist->size - 1; i++)
        arraylist->array[i] = arraylist->array[i + 1];

    // Decrease the size by one
    arraylist->size--;
}

void insert(ArrayList * arraylist, int value, int index)
{
    // Check if array is full and double capacity if so
    if(arraylist->size == arraylist->cap)
    {
        arraylist->cap *= 2;
        arraylist->array = realloc(arraylist->array, arraylist->cap);
    }

    // Shifts all elements to the right of array[index] including index to the right by one
    for(int i = arraylist->size; i > index; i--)
        arraylist->array[i] = arraylist->array[i - 1];

    // Adds value at the given index
    arraylist->array[index] = value;
    arraylist->size++;
}

void printList(ArrayList * arraylist)
{
    printf("[");

    // Print elements with commas in between them
    for(int i = 0; i < arraylist->size - 1; i++)
        printf("%d, ", arraylist->array[i]);
    
    printf("%d]\n", arraylist->array[arraylist->size - 1]);
}

void reverseList(ArrayList * arraylist)
{
    // Swap each set of outer values
    for(int i = 0; i < arraylist->size / 2; i++)
        swap(&arraylist->array[i], &arraylist->array[arraylist->size - 1 - i]);
}

void swap(int * num1, int * num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void merge(ArrayList * arraylist, int L, int R, int M)
{
    int length1 = M - L + 1;
    int length2 = R - M;

    // Create temp arrays for left and right subarrays
    int * arrL = (int *) malloc(sizeof(int) * length1);
    int * arrR = (int *) malloc(sizeof(int) * length2);

    // Copy left and right subarray elements into temp arrays
    for(int i = 0; i < length1; i++)
        arrL[i] = arraylist->array[i + L];

    for(int i = 0; i < length2; i++)
        arrR[i] = arraylist->array[M + 1 + i];

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
            arraylist->array[k] = arrL[i];
            i++;
        }
        else
        {
            arraylist->array[k] = arrR[j];
            j++;
        }
        
        k++;
    }
    
    // Copy any remaining elements in arrL[]
    while (i < length1)
    {
        arraylist->array[k] = arrL[i];
        i++;
        k++;
    }
 
    // Copy any remaining elements in arrR[]
    while (j < length2)
    {
        arraylist->array[k] = arrR[j];
        j++;
        k++;
    }

    // Free temp arrays
    free(arrL);
    free(arrR);
}

void sortList(ArrayList * arraylist, int L, int R)
{
    if(L < R)
    {
        int M = L + (R - L) / 2;

        // Sort left and right halves of array
        sortList(arraylist, L, M);
        sortList(arraylist, M + 1, R);

        // Merge both halves together
        merge(arraylist, L, R, M);
    }
}

void freeList(ArrayList * arraylist)
{
    free(arraylist->array);
    free(arraylist);
}