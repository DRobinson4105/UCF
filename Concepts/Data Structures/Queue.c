#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node * next;
};

Node * front, * rear;

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

void enQueue(int data)
{
    // Create the node dynamically
    Node * newNode = createNode(data);

    // If the queue is empty
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    // Add the new node to the end of the queue
    rear->next = newNode;
    rear = newNode;
}

Node * deQueue()
{
    // If the queue is empty
    if (front == NULL) return;

    // Save pointer of front node
    Node * deletedNode = front;

    // Shift front pointer
    front = front->next;

    // Set rear to NULL if queue becomes empty
    if(isEmpty())
        rear = NULL;

    return deletedNode;
}

Node * peek()
{
    return front;
}

int isEmpty()
{
    return front == NULL;
}