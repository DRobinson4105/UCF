#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PICTURES 23

int main()
{
    int S, L, midpoint, count, closestI, closestJ;
    
    char input;

    scanf("%d %d", &S, &L);
    char dump[80];

    int possibilities[S + 1][L + 1];

    // fill array with 1s
    for(int i = 0; i < S + 1; i++)
    {
        for(int j = 0; j < L + 1; j++)
            possibilities[i][j] = 1;
    }
    
    for(int picture = 1; picture <= MAX_PICTURES; picture++)
    {
        midpoint = 0;
        count = 0;
        closestI = -1;

        // find all valid possiblities
        for(int i = 0; i < S + 1; i++)
        {
            for(int j = 0; j < L + 1; j++)
            {
                if(possibilities[i][j] == 1)
                {
                    midpoint += i * picture + j;
                    count++;
                }
            }
        }

        // get average of all valid possiblities
        midpoint = (int)(midpoint / count);

        // find the closest possible boat location to the average
        for(int i = 0; i < S + 1; i++)
        {
            for(int j = 0; j < L + 1; j++)
            {
                if(closestI == -1 || abs(i * picture + j - midpoint) < abs(closestI * picture + closestJ - midpoint))
                {
                    closestI = i;
                    closestJ = j;
                }
            }
        }

        // make the midpoint the closest possible boat location
        midpoint = (closestI * picture + closestJ);

        // if there is only one possible boat location left or if there is no more pictures left to take
        if(count == 1 || picture == MAX_PICTURES)
        {
            printf("! %d\n", midpoint);
            fflush(stdout);
            break;
        }

        printf("? %d\n", midpoint);
        fflush(stdout);

        scanf(" %c", &input);
        fgets(dump, 80, stdin);

        if(input == 'B') // if the picture shows a boat, invalidate all possible locations that are not at the midpoint
        {
            for(int i = 0; i < S + 1; i++)
            {
                for(int j = 0; j < L + 1; j++)
                {
                    if(midpoint < i * picture + j || midpoint > i * picture + j)
                        possibilities[i][j] = 0;
                }
            }
        }
        else if(input == 'N') // if the picture shows no wake, invalidate all possible locations that are greater than or equal to the midpoint
        {
            for(int i = 0; i < S + 1; i++)
            {
                for(int j = 0; j < L + 1; j++)
                {
                    if(midpoint <= i * picture + j)
                        possibilities[i][j] = 0;
                }
            }
        }
        else // if the picture shows a wake, invalidate all possible locations that are less than or equal to the midpoint
        {
            for(int i = 0; i < S + 1; i++)
            {
                for(int j = 0; j < L + 1; j++)
                {
                    if(midpoint >= i * picture + j)
                        possibilities[i][j] = 0;
                }
            }   
        }

    }
    
    return 0;
}