#include <stdio.h>
#include <stdlib.h>

#define GARBAGE -1

// find the order of actions where the temp drop is greatest
void findBestCase(int * perm, int * used, int * firstAction, int ** followingActions, int n, int index, int * bestCase, int * bestTemp, int temp); 

int main()
{
    int n;
    int bestTemp = -100001;
    
    scanf("%d", &n);

    int * firstAction = (int *) malloc(sizeof(int) * n); // first action
    int * bestCase = (int *) malloc(sizeof(int) * n); // best case scenario
    int * used = (int *) calloc(n, sizeof(int));
    int * perm = (int *) malloc(sizeof(int) * n);
    int ** followingActions = (int **) malloc(sizeof(int *) * n); // all actions after first

    // initializing each array inside of the 2d array
    for(int i = 0; i < n; i++)
        followingActions[i] = (int *) malloc(sizeof(int) * n);
    
    // fill array for first actions
    for(int i = 0; i < n; i++)
        scanf("%d", &firstAction[i]);

    // fill 2d array for following actions
    for(int i = 0; i < n * n; i++)
        scanf("%d", &followingActions[i / n][i % n]);

    
    // find the order of actions for best temp drop and store it in best case
    findBestCase(perm, used, firstAction, followingActions, n, 0, bestCase, &bestTemp, 0);

    for(int i = 0; i < n; i++) // print the best order of actions
    {
        printf("%d", bestCase[i] + 1);
        printf((i < n - 1) ? " " : "\n"); // space out each value
    }

    return 0;
}

void findBestCase(int * perm, int * used, int * firstAction, int ** followingActions, int n, int index, int * bestCase, int * bestTemp, int temp)
{
    // Base Call - if new possibility was finished
    if(index == n)
    {
        // if the new temperature drop is better than the current best
        if(temp > *bestTemp) 
        {
            *bestTemp = temp; // replace best temperature value

            // replace each action in best case array
            for(int i = 0; i < n; i++)
                bestCase[i] = perm[i];
        }

        return;
    }

    // Recursive Call
    for(int value = 0; value < n; value++)
    {
        if(used[value] == 1) continue; // move on to next value if current value was already used

        used[value] = 1; // use the current value

        perm[index] = value; // add value to perm

        // add temperature change from the next action
        int tempChange = temp + firstAction[value];

        for(int i = 0; i < index; i++)
            tempChange += followingActions[perm[i]][value];

        // check all possiblities for action after current action
        findBestCase(perm, used, firstAction, followingActions, n, index + 1, bestCase, bestTemp, tempChange); 

        used[value] = 0;
        perm[index] = GARBAGE;
    }
}