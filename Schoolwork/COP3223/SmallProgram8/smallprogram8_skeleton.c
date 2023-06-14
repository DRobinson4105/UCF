//name
//professor
//course
//assignment

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

typedef struct{
    char * fname; //first name
	char * lname; //last name
	char * show; //favorite show
}record_t;

record_t * createArray(int maxsize);
//record_t * insert(record_t *myarray, int *maxsize, int *currentsize); 
void display(record_t *myarray, int currentsize);
//record_t *doubleIt(record_t *arr, int size); 
//int removeRecord(record_t *arr, int size, int index); 
//void freeRecords(record_t *arr, int size); 

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
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                //myarray = insert(myarray, &maxsize, &currentsize);
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
                //currentsize = removeRecord(myarray,currentsize,index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
				break;

            default:
                printf("Invalid Selection...\n");


        }

    }
	
	//freeRecords(myarray, currentsize);
	free(myarray);

	myarray = NULL;

	return 0;
}

record_t * createArray(int maxsize)
{
	record_t * arr = (record_t *) malloc(maxsize * sizeof(record_t));
	
	if(arr == NULL)
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}
	
	return arr;
}



void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");

	for(int x = 0; x < currentsize; ++x)
	{
	    printf("myarray[%d].fname = %s\n", x, (x + myarray)->fname); //try it with myarray[x].name
		printf("myarray[%d].lname = %s\n", x, (x + myarray)->lname); //try it with myarray[x].name
		printf("myarray[%d].show = %s\n", x, (x + myarray)->show); //try it with myarray[x].show
	}

	printf("---------------------------------\n");
}