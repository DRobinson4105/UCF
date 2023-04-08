#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAP 10

typedef struct Shipment Shipment;
typedef struct Heap Heap;

struct Shipment {
    int arrival;
    int expiration;
    int mass;
    int valid;
};

struct Heap {
    Shipment * arr; // Array to hold values
    int size; // Current number of elements in array
    int cap; // Max number of elements in array
};

// Allocates memory for a heap with a starting capacity 
// for the array of 10 and returns a pointer to it
Heap * createHeap();

// Add shipment to end of heap
void append(Heap * list, int a, int e, int m);

int main()
{
    Heap * shipments = createHeap();
    int numShipments;
    int a, e, m, start, end;

    scanf("%d", &numShipments);

    for (int i = 0; i < numShipments; i++)
    {
        scanf("%d %d %d", &a, &e, &m);
        append(shipments, a, e, m);
    }

    scanf("%d %d", &start, &end);

    for (int i = 0; i < numShipments; i++)
    {
        if (shipments->arr[i].expiration <= start || shipments->arr[i].arrival >= end)
        {
            shipments->arr[i].valid = 0;
            continue;
        }

        if (shipments->arr[i].expiration > end)
            shipments->arr[i].expiration = end;
    }

    shipments = freeHeap(shipments);

    return 0;
}

Heap * createHeap()
{
    // Allocate memory for heap
    Heap * newHeap = (Heap *) malloc(sizeof(Heap));

    // Initialize parts of heap
    newHeap->arr = (Shipment *) malloc(sizeof(Shipment) * STARTING_CAP);
    newHeap->size = 0;
    newHeap->cap = STARTING_CAP;
    
    // Return pointer to heap
    return newHeap;
}

void append(Heap * list, int a, int e, int m)
{
    // If heap has not been initialized
    if (list == NULL) return;

    // Double capacity of heap if heap is full
    if (list->size == list->cap)
    {
        list->arr = (int *) realloc(list->arr, list->cap * 2);
        list->cap *= 2;
    }

    // Add shipment to end of heap
    list->arr[list->size].arrival = a;
    list->arr[list->size].expiration = e;
    list->arr[list->size].mass = m;
    list->arr[list->size].valid = 1;
    list->size++;
}