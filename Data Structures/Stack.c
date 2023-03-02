#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    int data;
    Node * next;
};

Node * top;

Node * createNode(int data)
{
    // Create the node dynamically
    Node * res = (Node *) malloc(sizeof(Node));

    // Initialize the data in the node
    res->data = data;

    // Intialize the next pointer
    res->next = NULL;

    return res;
}

void push(int data)
{
    // Create the node dynamically
    Node * newNode = createNode(data);

    // If the stack is empty
    if (isEmpty(top))
        return newNode;

    // Add new node to top of stack
    newNode->next = top;
    top = newNode;

    // Save the new top
    top = newNode;
}

Node * pop()
{
    // If the stack is empty
    if (isEmpty(top))
        return NULL;

    // Save pointer of top node
    Node * deletedNode = top;

    // Move pointer down to next node
    top = top->next;

    return deletedNode;
}

Node * peek()
{
    return top;
}

int isEmpty()
{
    return top == NULL;
}

void printStack()
{
    while (top->next != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }

    printf("%d\n", top->data);
}