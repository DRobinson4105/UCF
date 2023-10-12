#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20

typedef struct {
    long long int xPos, yPos;
    char name[NAME_LENGTH + 1];
    long long int projection;
} Tugboat;

// Repeatedly splits array until each subarray has a length of one and then merges the arrays while sorting them
void mergeSort(Tugboat * tugboats, int L, int R);

// Merges two subarrays of tugboats where first subarray is tugboats[L..M] and second subarray is tugboats[M+1..R]
void merge(Tugboat * tugboats, int L, int R, int M);

int compTugboats(Tugboat tugboat1, Tugboat tugboat2);

int main()
{
    int shipX, shipY, numTugboats, lastBoat = 0, numUsed = 0;
    long long int finalPos, harborX, harborY;
    Tugboat * tugboats;

    // get ship location, harbor location, and number of tugboats from user
    scanf("%d %d %lld %lld %d", &shipX, &shipY, &harborX, &harborY, &numTugboats);

    // create array for all valid tugboats
    tugboats = (Tugboat *) malloc(sizeof(Tugboat) * numTugboats);

    // shift harbor location so that the ship is at the origin;
    harborX -= shipX;
    harborY -= shipY;

    // final position using dot product
    finalPos = harborX * harborX + harborY * harborY;

    // get tugboat information from user
    for(int boat = 0; boat < numTugboats; boat++)
    {
        scanf(" %lld %lld %s", &tugboats[boat].xPos, &tugboats[boat].yPos, tugboats[boat].name);
        
        // shift tugboat locations so ship is at origin
        tugboats[boat].xPos -= shipX;
        tugboats[boat].yPos -= shipY;

        // calculate projection using dot product
        tugboats[boat].projection = tugboats[boat].xPos * harborX + tugboats[boat].yPos * harborY;

        // remove tugboat if the closest position on the ship's route to the tugboat is where the ship starts
        if(tugboats[boat].projection < 0 || tugboats[boat].projection > finalPos)
        {
            boat--;
            numTugboats--;
        }
    }
    
    // sort tugboats by projected distance from the ship's starting location on the ship's route
    mergeSort(tugboats, 0, numTugboats - 1);

    // find number of tugboats used
    long long int lastProjection = -1;
    for (int i = 0; i < numTugboats; i++)
    {
        // if the tugboat will
        if (tugboats[i].projection != lastProjection)
        {
            numUsed++;
            lastProjection = tugboats[i].projection;
        }
    }

    printf("%d\n", numUsed);

    // print tugboats used
    lastProjection = -1;
    for (int i = 0; i < numTugboats ; i++)
    {
        if (tugboats[i].projection != lastProjection)
        {
            printf("%s\n", tugboats[i].name);
            lastProjection = tugboats[i].projection;
        }
    }
    
    // free dynamic array
    free(tugboats);

    return 0;
}

void mergeSort(Tugboat * tugboats, int L, int R)
{
    if(L < R)
    {
        int M = (L + R) / 2;

        mergeSort(tugboats, L, M);
        mergeSort(tugboats, M + 1, R);

        merge(tugboats, L, R, M);
    }
}

void merge(Tugboat * tugboats, int L, int R, int M)
{
    int i = 0, j = 0, k = L;

    int length1 = M - L + 1;
    int length2 = R - M;

    // create temp arrays for left and right subarrays
    Tugboat * arr1 = (Tugboat *) malloc(sizeof(Tugboat) * length1);
    Tugboat * arr2 = (Tugboat *) malloc(sizeof(Tugboat) * length2);

    // copy left and right subarray elements into the temp arrays
    for(int curr = 0; curr < length1; curr++)
        arr1[curr] = tugboats[curr + L];

    for(int curr = 0; curr < length2; curr++)
        arr2[curr] = tugboats[curr + M + 1];
    
    // merge the temp arrays into the subarray of tugboats[L..R]
    while (i < length1 && j < length2)
    {
        if (compTugboats(arr1[i], arr2[j]) < 0)
        {
            tugboats[k] = arr1[i];
            i++;
        }
        else
        {
            tugboats[k] = arr2[j];
            j++;
        }
        
        k++;
    }
    
    // copy any remaining values that have not been merged yet from arr1
    while (i < length1)
    {
        tugboats[k] = arr1[i];
        i++;
        k++;
    }
 
    // copy any remaining values that have not been merged yet from arr2
    while (j < length2)
    {
        tugboats[k] = arr2[j];
        j++;
        k++;
    }

    // free temp arrays
    free(arr1);
    free(arr2);
}

int compTugboats(Tugboat tugboat1, Tugboat tugboat2)
{    
    // first see if the projections are different and return the tugboat with the lower project
    if (tugboat1.projection < tugboat2.projection)
        return -1;
    else if (tugboat1.projection > tugboat2.projection)
        return 1;

    long long int diff1 = (tugboat1.xPos) * (tugboat1.xPos) + (tugboat1.yPos) * (tugboat1.yPos);
    long long int diff2 = (tugboat2.xPos) * (tugboat2.xPos) + (tugboat2.yPos) * (tugboat2.yPos);
    
    // then see if one tugboat is closer to the route than the other
    if (diff1 < diff2)
        return -1;
    else if (diff1 > diff2)
        return 1;
        
    // if they have the same projections and distance from route, then compare the names lexographically
    return strcmp(tugboat1.name, tugboat2.name);
}