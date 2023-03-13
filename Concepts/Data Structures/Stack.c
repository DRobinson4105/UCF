#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    int data; // Data that node holds
    Node * next; // Next node in a list or null if last node
};

struct Stack {
    Node * top; // Top node in stack
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and next parts of node
    newNode->data = value;
    newNode->next = NULL;

    // Return pointer to node
    return newNode;
}

// Add a new value to top of stack
Node * push(Stack * stack, int value)
{
    // Create the node dynamically
    Node * newNode = createNode(value);

    // Add new node to top of stack
    newNode->next = stack->top;

    // Save the new top
    stack->top = newNode;
}

// Remove the top value in stack
Node * pop(Stack * stack)
{
    // If the stack is empty
    if (isEmpty(stack)) return;

    // Save pointer of top node
    Node * deletedNode = stack->top;

    // Shift top of stack to next node
    stack->top = stack->top->next;

    // Free dynamic memory for removed node
    free(deletedNode);
}

// Return the value that is at the top of the stack
int peek(Stack * stack)
{
    // If the queue is empty
    if (isEmpty(stack))
        return -1;

    // Return next value in queue
    return stack->top->data;
}

// Free memory for all nodes in stack
void deleteStack(Stack * stack)
{
    // While queue is not empty
    while (!isEmpty(stack))
        pop(stack);
}

// Check if a stack is empty
int isEmpty(Stack * stack)
{
    return stack->top == NULL;
}

// Print all values in stack starting at the top
void printStack(Stack * stack)
{
    Node * curr = stack->top;
    
    // Print each value in the stack
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}