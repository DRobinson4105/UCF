// This program demonstrates how to implement
// some common priority queue / heap functions

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Macros for finding parent and children indices
#define PARENT(index)  (((index)-1)/2)
#define LEFT(index)    (((index)*2)+1)
#define RIGHT(index)   (((index)*2)+2)

// Default size of the heap
#define DEFAULT_CAP 10

// The alias for the heap
typedef struct Shipment Shipment;
typedef struct Heap Heap;

struct Shipment {
    int arrival;
    int expiration;
    int mass;
};
struct Heap {
    Shipment * array;
    int size, cap;
};

// Prototypes
int        higherPriorityThan(Shipment first, Shipment second);
Heap *     createHeap();
void       deleteHeap(Heap * hp);
void       swap(Heap * hp, int index1, int index2);
void       percolateUp(Heap * hp, int index);
void       percolateDown(Heap * hp, int index);
void       append(Heap * hp, Shipment value);
void       enqueue(Heap * hp, Shipment value);
void       dequeue(Heap * hp); 
Shipment   front(Heap * hp);
int        isEmpty(Heap * hp);
void       delete(Heap * hp, int index);
void       merge(Shipment * array, int low, int mid, int high);
void       mergeSort(Shipment * array, int low, int high);
int update(Heap * hp, int oldTime, int newTime, double consumeRate);
int canDo(Shipment * array, int numShipments, double consumeRate, int start, int end);
void printHeap(Heap * hp);

int main()
{
    Shipment * shipments;
    Shipment currShipment;
    int numShipments;
    int start, end;

    scanf("%d", &numShipments);

    shipments = (Shipment *) malloc(sizeof(Shipment) * numShipments);

    for (int i = 0; i < numShipments; i++)
    {
        scanf("%d %d %d", &currShipment.arrival, &currShipment.expiration, &currShipment.mass);
        shipments[i] = currShipment;
    }

    scanf("%d %d", &start, &end);

    for (int i = 0; i < numShipments; i++)
    {
        if (shipments[i].expiration <= start || shipments[i].arrival >= end)
        {
            i--;
            numShipments--;
            continue;
        }

        if (shipments[i].expiration > end)
            shipments[i].expiration = end;
    }

    mergeSort(shipments, 0, numShipments - 1);

    printf("%d\n", canDo(shipments, numShipments, 0.3, start, end));

    return 0;
}

void merge(Shipment * array, int low, int mid, int high)
{
    int length1 = mid - low + 1;
    int length2 = high - mid;

    // Create temp arrays for left and right subarrays
    Shipment * arrL = (Shipment *) malloc(sizeof(Shipment) * length1);
    Shipment * arrR = (Shipment *) malloc(sizeof(Shipment) * length2);

    // Copy left and right subarray elements into temp arrays
    for(int i = 0; i < length1; i++)
        arrL[i] = array[i + low];

    for(int i = 0; i < length2; i++)
        arrR[i] = array[mid + 1 + i];

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray
    
    // Merge temp arrays back into array[L..R]
    while (i < length1 && j < length2)
    {
        // If arrL[i] is less than or equal to arrR[j] then add arrL[i] to the 
        // next index in the merged subarray and move to the next value in arrL[]
        if (arrL[i].arrival <= arrR[j].arrival)
            array[k++] = arrL[i++];
        else
            array[k++] = arrR[j++];
    }
    
    // Copy any remaining elements in arrL[]
    while (i < length1)
        array[k++] = arrL[i++];
 
    // Copy any remaining elements in arrR[]
    while (j < length2)
        array[k++] = arrR[j++];

    // Free temp arrays
    free(arrL);
    free(arrR);
}

void mergeSort(Shipment * array, int low, int high)
{
    // If size of subarray is 0 or 1, do nothing
    if(low >= high) return;

    int mid = (low + high) / 2; // Midpoint of subarray

    // Sort left and right halves of array
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    // Merge both halves together
    merge(array, low, mid, high);
}

// Functions
// Function to check if the first value is higher priority than the second
// Return 1 if the first is higher priority
// Return 0 otherwise
// This function will be dependent on the type of heap
int higherPriorityThan(Shipment first, Shipment second) {
    if (first.expiration < second.expiration) return 1;
    return 0;
}

// Function to create a heap
Heap * createHeap() {
    // Allocate
    Heap * res = (Heap *) malloc(sizeof(Heap));

    // Intialize (array list)
    res->size = 0;
    res->cap = DEFAULT_CAP;
    res->array = (Shipment *) malloc(
                 sizeof(Shipment) * res->cap);
    
    // Return
    return res;
}

// Function to delete all the memory in the heap
void deleteHeap(Heap * hp) {
    // TODO: Potentially free the values in the 
    //       heap's array

    // Free the array itself
    free(hp->array);

    // Free the heap
    free(hp);
}

// Function to swap values in the heap
void swap(Heap * hp, int index1, int index2) {
    Shipment tmp = hp->array[index1];
    hp->array[index1] = hp->array[index2];
    hp->array[index2] = tmp;
}

// Function to move values up the heap while higher priority than parent
void percolateUp(Heap * hp, int index) {
    // Loop while the index has a parent
    while (index != 0) {
        // Find the parent
        int parIndex = PARENT(index);

        // Check if we are higher priority than
        // parent
        if (higherPriorityThan(hp->array[index], 
                               hp->array[parIndex])) {
            // Swap to the parent
            swap(hp, index, parIndex);
        
            // The value is now in the parent's location
            index = parIndex;
        } else {
            // The node can stop moving up
            return;
        }
    }
}

// Function to move values down the heap while a child has higher priority
void percolateDown(Heap * hp, int index) {
    int swapped = 0;
    // Loop until there are no more swaps
    do {
        // Set that there are no swaps for the current iteration
        swapped = 0;

        // Track the best index
        int bestIndex = index;

        // Check if a left child is better than best
        int leftIndex = LEFT(index);
        if (leftIndex < hp->size && 
            higherPriorityThan(hp->array[leftIndex], hp->array[bestIndex])) {
            bestIndex = leftIndex;
        }

        // Check if a right child is better than best
        int rightIndex = RIGHT(index);
        if (rightIndex < hp->size && 
            higherPriorityThan(hp->array[rightIndex], hp->array[bestIndex])) {
            bestIndex = rightIndex;
        }

        // Check if a swap is needed
        if (bestIndex != index) {
            swap(hp, bestIndex, index);
            swapped = 1;
            index = bestIndex;
        }
    } while (swapped);
}

// Function to append a value to the end of an array list (heap)
void append(Heap * hp, Shipment value) {
    // Check if the array was full
    if (hp->size == hp->cap)
    {
        hp->cap *= 2;
        hp->array = (Shipment *) realloc(hp->array, sizeof(Shipment) * hp->cap);
    }
    
    // Add to the end
    hp->array[hp->size] = value;

    // Update size
    hp->size++;
}

void delete(Heap * hp, int index)
{
    if (hp == NULL || isEmpty(hp)) return;

    for (int i = index; i < hp->size - 1; i++)
        hp->array[i] = hp->array[i + 1];

    hp->size--;
}

// Add a value to the heap
// Insert at end and percolate up
void enqueue(Heap * hp, Shipment value) {
    append(hp, value);
    percolateUp(hp, hp->size - 1);
}

// Function to remove the highest priority element from a heap
// Move last value to the top and percolate down
void dequeue(Heap * hp) {
    swap(hp, 0, hp->size - 1);
    hp->size--;
    percolateDown(hp, 0);
}

// Function to get the highest priority element of the heap (root)
Shipment front(Heap * hp) {
    return hp->array[0];
}
 
// Function to check if a heap is empty
int isEmpty(Heap * hp) {
    return (hp->size == 0);
}

int update(Heap * hp, int oldTime, int newTime, double consumeRate)
{
    int curTime = oldTime;
    double consumptionTime, finishTime;
    while (!isEmpty(hp))
    {
        consumptionTime = hp->array[0].mass / consumeRate;
        finishTime = consumptionTime + curTime;

        if (finishTime > hp->array[0].expiration)
            finishTime = hp->array[0].expiration;

        if (finishTime <= newTime)
        {
            curTime = finishTime;
            dequeue(hp);
        }
        else
        {
            hp->array[0].mass -= consumeRate * (newTime - curTime);
            return 1;
        }
    }

    return 0;
}

int canDo(Shipment * array, int numShipments, double consumeRate, int start, int end)
{
    Heap * pq = createHeap();

    enqueue(pq, array[0]);

    int curTime = start;
    int newTime;
    int completedUpdate;

    for (int i = 1; i < numShipments; i++)
    {
        newTime = front(pq).expiration;
        completedUpdate = update(pq, curTime, newTime, consumeRate);
        curTime = newTime;

        if (!completedUpdate) return 0;

        enqueue(pq, array[i]);
    }

    completedUpdate = update(pq, curTime, end, consumeRate);

    deleteHeap(pq);

    return completedUpdate;
}

void printHeap(Heap * hp)
{
    if (hp == NULL){
        printf("????");
        return;
    }
    printf("Heap:\n");
    for (int i = 0; i < hp->size; i++)
    {
        printf("%d: %d %d %d\n", i + 1, hp->array[i].arrival, hp->array[i].expiration, hp->array[i].mass);
    }
    printf("\n");
}