// This program demonstrates how to implement
// some common priority queue / heap functions

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Macros for finding parent and children indices
#define PARENT(index)  (((index)-1)/2)
#define LEFT(index)    (((index)*2)+1)
#define RIGHT(index)   (((index)*2)+2)

// Max size of the heap
#define DEFAULT_CAP 200000

typedef struct Shipment Shipment;
typedef struct Heap Heap;

struct Shipment {
    int arrival; // arrival time
    int expiration; // expiration time
    double mass; // shipment mass
};
struct Heap {
    Shipment * array; // array to hold elements in heap
    int size; // current number of elements in heap
    int cap; // max number of elements in heap 
};

// Allocate memory for heap and initalize it
// Return pointer to heap
Heap * createHeap();

// Delete all the memory in the heap
void freeHeap(Heap * hp);

// Swap values at index1 and index2 in the heap
void swap(Heap * hp, int index1, int index2);

// Move values up the heap while higher priority than parent
void percolateUp(Heap * hp, int index);

// Move values down the heap while a child has higher priority
void percolateDown(Heap * hp, int index);

// Append a value to the end of a heap
void append(Heap * hp, Shipment value);

// Add a value to the heap
// Insert at end and percolate up
void enqueue(Heap * hp, Shipment value);

// Remove the highest priority element from a heap
// Move last value to the top and percolate down
void dequeue(Heap * hp);

// Function to get the highest priority element of the heap which is at the zeroth index
Shipment front(Heap * hp);

// Function to check if a heap is empty
int isEmpty(Heap * hp);

// Merges and sorts two subarrays of elements where 
// first subarray is array[low..mid] and second subarray 
// is array[mid+1..high]
void merge(Shipment * array, int low, int mid, int high);

// Repeatedly splits array until each subarray has a 
// length of 1 or 0 and then merges and sorts the subarrays
void mergeSort(Shipment * array, int low, int high);

// Remove the shipments that would be consumed between the given old and new times
// Return 1 if the update was successful
// Return 0 if there was not enough food at the current consumption rate
int update(Heap * hp, int oldTime, int newTime, double consumeRate);

// Check if the guessed consumption rate works for the given array of shipments
int canDo(Shipment * array, int numShipments, double consumeRate, int start, int end);

int main()
{
    Shipment * shipments; // array of shipments from input
    int numShipments; // number of shipments
    int start, end; // starting and ending eating time of the crew
    double lowerBound, upperBound, mid; // used for binary search
    int totalMass = 0;

    scanf("%d", &numShipments);

    // Allocate heap memory for given number of shipments
    shipments = (Shipment *) malloc(sizeof(Shipment) * numShipments);

    // Get input for all shipments
    for (int i = 0; i < numShipments; i++)
    {
        scanf("%d %d %lf", &shipments[i].arrival, &shipments[i].expiration, &shipments[i].mass);
        totalMass += shipments[i].mass;
    }

    scanf("%d %d", &start, &end);

    // Clamp all shipments to start and end eating time
    for (int i = 0; i < numShipments; i++)
    {
        // If shipment would be invalid by expiring before start or arriving after end
        if (shipments[i].expiration <= start || shipments[i].arrival >= end)
        {
            totalMass -= shipments[i].mass;
            i--;
            numShipments--;
            continue;
        }

        // If shipment is valid but expires after end
        if (shipments[i].expiration > end)
            shipments[i].expiration = end;
        
        // If shipment is valid but arrives before start
        if (shipments[i].arrival < start)
            shipments[i].arrival = start;
    }

    // Sort shipments based on arrival time
    mergeSort(shipments, 0, numShipments - 1);

    lowerBound = 0;
    upperBound = totalMass / (end - start);

    // Binary search until valid bound has an absolute error of 10^-5
    while (upperBound - lowerBound > 1e-5)
    {
        mid = (lowerBound + upperBound) / 2;

        if (canDo(shipments, numShipments, mid, start, end))
            lowerBound = mid;
        else
            upperBound = mid;
    }

    printf("%lf\n", upperBound);

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
    
    // Merge temp arrays back into array[low..high]
    while (i < length1 && j < length2)
    {
        // Add the lower arrival time to merged array
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

    // Midpoint of subarray
    int mid = (low + high) / 2;

    // Sort left and right halves of array
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    // Merge both halves together
    merge(array, low, mid, high);
}

Heap * createHeap() {
    // Allocate dynamic memory for heap
    Heap * newHeap = (Heap *) malloc(sizeof(Heap));

    // Intialize all parts of heap
    newHeap->size = 0;
    newHeap->cap = DEFAULT_CAP;
    newHeap->array = (Shipment *) malloc(sizeof(Shipment) * DEFAULT_CAP);
    
    // Return
    return newHeap;
}

void freeHeap(Heap * hp) 
{
    free(hp->array);
    free(hp);
}

void swap(Heap * hp, int index1, int index2) {
    Shipment tmp = hp->array[index1];
    hp->array[index1] = hp->array[index2];
    hp->array[index2] = tmp;
}

void percolateUp(Heap * hp, int index) {
    // Loop while the index has a parent
    while (index != 0) {
        // Index of parent
        int parIndex = PARENT(index);

        // Check if current element is higher priority than parent
        if (hp->array[index].expiration < hp->array[parIndex].expiration)
        {
            // Swap to the parent
            swap(hp, index, parIndex);
            index = parIndex;
        } 
        
        // Done percolating
        else
            return;
    }
}

void percolateDown(Heap * hp, int index)
{
    int swapped = 1;
    // Loop until there are no more swaps
    while (swapped)
    {
        // Set that there are no swaps for the current iteration
        swapped = 0;

        // Track the best index
        int bestIndex = index;

        // Check if a left child is better than best
        int leftIndex = LEFT(index);
        if (leftIndex < hp->size &&
            hp->array[leftIndex].expiration < hp->array[bestIndex].expiration)
            bestIndex = leftIndex;

        // Check if a right child is better than best
        int rightIndex = RIGHT(index);
        if (rightIndex < hp->size &&
            hp->array[rightIndex].expiration < hp->array[bestIndex].expiration)
            bestIndex = rightIndex;

        // Check if a swap is needed
        if (bestIndex != index)
        {
            swap(hp, bestIndex, index);
            swapped = 1;
            index = bestIndex;
        }
    }
}

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

void enqueue(Heap * hp, Shipment value) {
    append(hp, value);
    percolateUp(hp, hp->size - 1);
}

void dequeue(Heap * hp) {
    swap(hp, 0, hp->size - 1);
    hp->size--;
    percolateDown(hp, 0);
}

Shipment front(Heap * hp) {
    return hp->array[0];
}
 
int isEmpty(Heap * hp) {
    return (hp->size == 0);
}

int update(Heap * hp, int oldTime, int newTime, double consumeRate)
{
    double consumptionTime, finishTime;

    // Keep track of the current time
    int curTime = oldTime;

    // Loop while there is some value in the heap
    while (!isEmpty(hp) && curTime < newTime)
    {
        // Determine the time required to finish consuming the current shipment 
        consumptionTime = hp->array[0].mass / consumeRate;

        // Determine the time when the shipment would finish consumption
        finishTime = consumptionTime + curTime;


        // Check if we cannot finish the shipment before spoiling
        if (finishTime > hp->array[0].expiration)
            finishTime = hp->array[0].expiration;

        // Check if we can finish the shipment before the end of the update
        if (finishTime <= newTime)
        {
            // Update time and remove from heap
            curTime = finishTime;
            dequeue(hp);
        }
        else
        {
            // Update the remaining mass of the shipment and stop the simulation
            hp->array[0].mass -= consumeRate * (newTime - curTime);
            return 1;
        }
    }

    // If the shipments fed the crew until the new time
    return (curTime == newTime);
}

int canDo(Shipment * array, int numShipments, double consumeRate, int start, int end)
{
    // Create a heap used as a priority queue
    Heap * pq = createHeap();

    // Add first shipment to priority queue
    enqueue(pq, array[0]);

    int curTime = start;
    int completedUpdate;
    
    // Loop through the remaining shipments
    for (int i = 1; i < numShipments; i++)
    {
        // Update the heap based on the arrival of the current shipment
        completedUpdate = update(pq, curTime, array[i].arrival, consumeRate);
        curTime = array[i].arrival;

        // If the crew starved during the update
        if (!completedUpdate) return 0;

        // Add current shipment to priority queue
        enqueue(pq, array[i]);
    }

    // Update to end of crew eating time
    completedUpdate = update(pq, curTime, end, consumeRate);

    // Free heap memory
    freeHeap(pq);

    // Return based on the validity of the last update
    return completedUpdate;
}