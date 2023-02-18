#include <stdio.h>
#include <stdlib.h>

void merge(int * array, int l, int r, int m);

void mergeSort(int * array, int l, int r);

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

void merge(int * array, int l, int r, int m)
{
    int i = 0, j = 0, k = l;

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = array[i + l];

    for(int i = 0; i < n2; i++)
        R[i] = array[m + 1 + i];

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        
        k++;
    }
 
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int * array, int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, r, m);
    }
}