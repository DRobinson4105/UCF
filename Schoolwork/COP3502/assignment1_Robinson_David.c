#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define STARTING_CAP 5

typedef struct {
    int start_x, start_y, delta_x, delta_y, start_time;
    char name[NAME_LEN + 1];
} Boat;

typedef struct {
    Boat * array;
    int size, capacity;
} ArrayList;

void initArrayList(ArrayList * list)
{
    list->array = (Boat *) malloc(sizeof(Boat) * STARTING_CAP);
    list->size = 0;
    list->capacity = STARTING_CAP;
}

void appendToList(ArrayList * list, Boat newBoat)
{
    if(list->capacity == list->size)
    {
        list->capacity *= 2;
        list->array = (Boat *) realloc(list->array, sizeof(list->array) * list->capacity);
    }
    list->array[list->size] = newBoat;
    list->size++;
}

int query(int x, int y, int storm_width, int storm_height, int world_width, int world_height, ArrayList * list, int cur_time, int should_print)
{
    int numBoats = 0;
    int currX, currY, offsetX, offsetY;

    for (int i = 0; i < list->size; i++) // loop through each boat in the list
    {
        // get the current position before wrapping by using the starting position and moving one for each minute passed since boat was created in the direction given
        currX = list->array[i].start_x + (cur_time - list->array[i].start_time) * list->array[i].delta_x;
        currY = list->array[i].start_y + (cur_time - list->array[i].start_time) * list->array[i].delta_y;

        // get the offset between the storm's starting coordinates and the boat on the grid
        offsetX = ((currX - x) + world_width) % world_width;
        offsetY = ((currY - y) + world_height) % world_height;

        if(offsetX < storm_width && offsetY < storm_height) // if the boat is in the storm
        {
            numBoats++;
            if(should_print)
                printf("%s\n", list->array[i].name);
        }
    }

    return numBoats;
}

int main()
{
    int height, width, option, t;
    int currTime = 0;
    char direction;
    int storm_x, storm_y, storm_w, storm_h;
    int numBoats;
    Boat newBoat;

    scanf("%d %d", &width, &height);

    ArrayList * rows = (ArrayList *) malloc(sizeof(ArrayList) * height);
    ArrayList * columns = (ArrayList *) malloc(sizeof(ArrayList) * width);

    // initialize each row and column as an arraylist
    for (int i = 0; i < height; i++)
    {
        initArrayList(&rows[i]);
    }
        for (int i = 0; i < width; i++)
    {
        initArrayList(&columns[i]);
    }
    
    scanf(" %d", &option);

    while(option != 4)
    {
        switch(option)
        {
            case 1: // if the user wants to add a new boat
                scanf(" %d %d %c %s", &newBoat.start_x, &newBoat.start_y, &direction, newBoat.name);
                newBoat.start_time = currTime;
                
                switch(direction)
                {
                    case 'U':
                        newBoat.delta_x = 0;
                        newBoat.delta_y = 1;
                        appendToList(&columns[newBoat.start_x - 1], newBoat); // add boat to the column that the boat will stay in no matter the time
                        break;

                    case 'D':
                        newBoat.delta_x = 0;
                        newBoat.delta_y = -1;
                        appendToList(&columns[newBoat.start_x - 1], newBoat); // add boat to the column that the boat will stay in no matter the time
                        break;

                    case 'R':
                        newBoat.delta_x = 1;
                        newBoat.delta_y = 0;
                        appendToList(&rows[newBoat.start_y - 1], newBoat); // add boat to the row that the boat will stay in no matter the time
                        break;

                    case 'L':
                        newBoat.delta_x = -1;
                        newBoat.delta_y = 0;
                        appendToList(&rows[newBoat.start_y - 1], newBoat); // add boat to the row that the boat will stay in no matter the time
                        break;
                }
                break;

            case 2: // if the user wants to pass t amount of minutes
                scanf(" %d", &t);
                currTime += t;
                break;

            case 3:
                scanf(" %d %d %d %d", &storm_x, &storm_y, &storm_w, &storm_h);
                numBoats = 0;

                for(int i = 0; i < height; i++) // check for any boat in a row that is affected by the storm
                    numBoats += query(storm_x, storm_y, storm_w, storm_h, width, height, &rows[i], currTime, 0);
                
                for(int i = 0; i < width; i++) // check for any boat in a column that is affected by the storm
                    numBoats += query(storm_x, storm_y, storm_w, storm_h, width, height, &columns[i], currTime, 0);

                printf("%d\n", numBoats);
                
                // loop through every row and column again but print the boat names instead of counting the number of boats
                for(int i = 0; i < height; i++)
                    query(storm_x, storm_y, storm_w, storm_h, width, height, &rows[i], currTime, 1);
                for(int i = 0; i < width; i++)
                    query(storm_x, storm_y, storm_w, storm_h, width, height, &columns[i], currTime, 1);

                break;
        }
        scanf("%d", &option);
    }
    
    // free all dynamic memory

    for(int i = 0; i < height; i++)
        free(rows[i].array);

    for(int i = 0; i < width; i++)
        free(columns[i].array);

    free(rows);
    free(columns);
}