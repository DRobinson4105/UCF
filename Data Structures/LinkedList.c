#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    int data;
    Node * next;
};

Node * head, * tail;

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

void insertHead(int data)
{
    // Create the node dynamically
    Node * newNode = createNode(data);

    // Have the new head point to the old head
    newNode->next = head;

    // Save the new head
    head = newNode;
}

void insertTail(int data)
{
    // Create the node dynamically
    Node * newNode = createNode(data);

    // If the list is empty
    if (tail == NULL)
        return newNode;

    // Have the old tail point to the new tail
    tail->next = newNode;

    // Save the new tail
    tail = newNode;
}

void removeHead(Node * head)
{
    // If the list is empty
    if (isEmpty(head))
        return NULL;

    // Get the pointer to the new head of the list
    Node * newHead = head->next;

    // Delete the old head
    free(head);

    // Save the new head
    head = newHead;
}

void removeTail(Node * head)
{
    // If the list is empty
    if (isEmpty(head))
        return NULL;

    // If the list only has one node
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    // Get the pointer to the second to last node
    Node * cur = head;

    while (cur->next->next != NULL)
        cur = cur->next;

    // Delete the old tail
    free(cur->next);
    cur->next = NULL;

    // Save the new tail
    tail = cur;
}

void deleteList(Node * head)
{
    // While list is not empty
    while (!isEmpty(head))
        removeHead(head);
}

int isEmpty(Node * head)
{
    return head == NULL;
}

void printList(Node * head)
{
    while (head->next != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("%d\n", head->data);
}