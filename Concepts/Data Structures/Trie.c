#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
    int data;
    Node ** children;
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value);

int main()
{
    return 0;
}

Node * createNode(int value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize parts of node
    newNode->data = value;
    newNode->children = (Node **) malloc(sizeof(Node *) * 26);

    // Return pointer to node
    return newNode;
}

int search(Node * root, char * key)
{
    Node * curr = root;
    int len = strlen(key);

    for (int i = 0; i < len && curr != NULL; i++)
        curr = curr->children[key[i] - 48];

    if (curr == NULL) return -1;

    return curr->data;
}