#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    int data; // Data that node holds
    Node * next; // Next node in stack
};

struct Stack {
    Node * top; // Top node in stack
    int height; // Number of nodes in stack
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int val);

// Initialize a stack with a null pointer for the top node and a height of 0
Stack * stackInitialize();

// Add a new value to top of stack
void push(Stack * stack, int value);

// Remove the top value in stack
int pop(Stack * stack);

// Return the value that is second from the top of the stack
int peekSecond(Stack * stack);

// Free memory for all nodes in stack
void freeStack(Stack * stack);

int main()
{
    // Number of possible quarters
    long long int numQuarters = 0;

    // Total distance from each room to the main entrance
    long long int sumCorridors = 0;

    // To keep track of current room from the input
    int currRoom;

    // If the employee is going back to main entrance
    int justDeletedNode = 0;

    // Stack to track room
    Stack * rooms = stackInitialize();

    // Get first room
    scanf("%d", &currRoom);

    while (currRoom != -1)
    {
        if (peekSecond(rooms) == currRoom)
        {
            if (!justDeletedNode)
            {
                numQuarters++;
                sumCorridors += rooms->height - 1;
            }

            pop(rooms);
            justDeletedNode = 1;
        }
        else
        {
            push(rooms, currRoom);
            justDeletedNode = 0;
        }

        scanf("%d", &currRoom);
    }

    printf("%lld %lld\n", numQuarters, sumCorridors);

    freeStack(rooms);
    
    return 0;
}

Node * createNode(int val)
{
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

Stack * stackInitialize()
{
    Stack * newStack = (Stack *) malloc(sizeof(Stack));

    newStack->top = NULL;
    newStack->height = 0;

    return newStack;
}

void push(Stack * stack, int value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // Add new node to top of stack
    newNode->next = stack->top;

    // Save the new top
    stack->top = newNode;

    // Increase height of stack
    stack->height++;
}

int pop(Stack * stack)
{
    // If the stack is empty
    if (stack->top == NULL) return -1;

    // Save pointer of top node and its data
    Node * delNode = stack->top;
    int delVal = delNode->data;

    // Shift top of stack to next node
    stack->top = stack->top->next;

    // Free dynamic memory for removed node
    free(delNode);

    // Decrease height of stack
    stack->height--;

    // Return deleted value
    return delVal;
}

int peek(Stack * stack)
{
    // If the stack is empty
    if (stack->top == NULL) return -1;

    // Return top value in stack
    return stack->top->data;
}

int peekSecond(Stack * stack)
{
    // If the queue doesn't have a second node
    if (stack->top == NULL || stack->top->next == NULL) return -1;

    // Return second value in stack
    return stack->top->next->data;
}

void freeStack(Stack * stack)
{
    // While queue is not empty
    while (stack->top != NULL)
        pop(stack);

    free(stack);
}