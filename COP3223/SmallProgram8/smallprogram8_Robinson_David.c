//David Robinson
//Dr. Steinberg
//COP3223C Section 1
//Small Program 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

typedef struct{
    char * fname; //first name
	char * lname; //last name
	char * show; //favorite show
}record_t;

record_t * createArray(int maxsize); // create the array

record_t * insert(record_t *myarray, int *maxsize, int *currentsize); // insert a new record into the array

void display(record_t *myarray, int currentsize); // display all of the records

record_t *doubleIt(record_t *arr, int size); // double the size of the array

int removeRecord(record_t *arr, int size, int index); // remove a record from the array

void freeRecords(record_t *arr, int size); // free the memory for the aray

int main(void)
{
	int maxsize;

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);

	record_t *myarray = createArray(maxsize);
	
	int currentsize = 0;
	int option = -1;

	while(option != 0)
    {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf(" %d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2:
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                currentsize = removeRecord(myarray,currentsize,index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
				break;

            default:
                printf("Invalid Selection...\n");
                break;

        }

    }
	
	freeRecords(myarray, currentsize); // free the memory of all of the records
	free(myarray); // free the memory for the array

	myarray = NULL;

	return 0;
}

record_t * createArray(int maxsize)
{
	record_t * arr = (record_t *) malloc(maxsize * sizeof(record_t)); // allocates memory for the array
	
	if(arr == NULL) // exits the program if there was a malloc error
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}
	
	return arr;
}

record_t * insert(record_t *myarray, int *maxsize, int *currentsize)
{
    char * first = (char *) malloc(LIMIT * sizeof(char)); // allocates memory for the first name
    char * last = (char *) malloc(LIMIT * sizeof(char)); // allocates memory for the last name
    char * favshow = (char *) malloc(LIMIT * sizeof(char)); // allocates memory for the show

    if(first == NULL || last == NULL || favshow == NULL) // exits the program if there was a malloc error
	{
		printf("malloc error in insert...program exiting\n");
		exit(1);
	}
    
    if(*currentsize == *maxsize) // double the size of the array if the array is full
    {
        printf("Array is full...Need to doubleIt...\n");
        myarray = doubleIt(myarray, *maxsize);
        *maxsize *= 2;
    }

    printf("Enter the first name: ");
    scanf(" %s", first);

    printf("Enter the last name: ");
    scanf(" %s", last);

    printf("Enter favorite show: ");
    scanf(" %[^\n]", favshow);
        
    (*currentsize + myarray)->fname = first;
    (*currentsize + myarray)->lname = last;
    (*currentsize + myarray)->show = favshow;
        
    *currentsize += 1;

    return myarray;
}

void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");
	for(int x = 0; x < currentsize; ++x)
	{
	    printf("myarray[%d].fname = %s\n", x, myarray[x].fname); //try it with myarray[x].name
		printf("myarray[%d].lname = %s\n", x, myarray[x].lname); //try it with myarray[x].name
		printf("myarray[%d].show =  %s\n\n", x, myarray[x].show); //try it with myarray[x].show
	}

	printf("---------------------------------\n");
}

record_t *doubleIt(record_t *arr, int size)
{
    record_t * temp = (record_t *) malloc(size * 2 * sizeof(record_t));

    if(temp == NULL)
	{
		printf("malloc error in doubleIt...program exiting\n");
		exit(1);
	}

    for(int i = 0; i < size; i++)
    {
        (i + temp)->fname = (i + arr)->fname;
        (i + temp)->lname = (i + arr)->lname;
        (i + temp)->show = (i + arr)->show;
    }

    free(arr);

    return temp;
}

int removeRecord(record_t *arr, int size, int index)
{
    if(index >= size || index < 0) // if the user asks for an index that does not exist in the array
    {
        printf("Invalid Index\n");
        return size;
    }
    else
    {
        free((arr + index)->fname); // free the memory of the first name at the index
        free((arr + index)->lname); // free the memory of the last name at the index
        free((arr + index)->show); // free the memory of the show at the index
        
        for(int i = index; i < size; i++) // shift all of the indexes down by 1 after the removed index
        {
            (i + arr)->fname = (i + 1 + arr)->fname;
            (i + arr)->lname = (i + 1 + arr)->lname;
            (i + arr)->show = (i + 1 + arr)->show;
        }

        return size - 1;
    }

}

void freeRecords(record_t *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        free((i + arr)->fname); // free all of the first names in the array
        free((i + arr)->lname); // free all of the last names in the array
        free((i + arr)->show); // free all of the shows in the array
    }

}