#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data; // Data that node holds
    Node * left; // Pointer to left branch
    Node * right; // Pointer to right branch
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value);

// Insert value into BST and return the new root of the BST
Node * insertNode(Node * root, int value);

// Return the max depth of BST from the given root
int getMaxDepth(Node * root);

// Check if BST is also an AVL Tree
int IsValidAVL(Node * root);

// Print BST in order
void printInOrderTree(Node * root);

int main()
{
    return 0;
}

Node * createNode(int value)
{
    // Create the node dynamically
    Node * newNode = (Node *) malloc(sizeof(Node));

    // Initialize data and pointers of node
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // Return pointer to node
    return newNode;
}

Node * insertNode(Node * root, int value)
{
    // Add Node
    if (root == NULL) return createNode(value);

    // If value needs to be added to left branch of current node
    if (value < root->data)
        root->left  = insertNode(root->left, value);

    // If value needs to be added to right branch of current node
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    // Do nothing if value already exists
    return root;
}

Node * insertNode(Node * root, int value)
{
    // Add Node
    if (root == NULL) return createNode(value);

    // If value needs to be added to left branch of current node
    if (value < root->data)
        root->left  = insertNode(root->left, value);

    // If value needs to be added to right branch of current node
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    // Do nothing if value already exists
    return root;
}

int getMaxDepth(Node * root)
{
    // If end of branch was reached
    if (root == NULL) return 0;

    // Get the max depth of the left branch
    int left = getMaxDepth(root->left);

    // Get the max depth of the right branch
    int right = getMaxDepth(root->right);

    // Return the higher depth + one for the root node
    if (left > right)
        return 1 + left;

    return 1 + right;
}

int IsValidAVL(Node * root)
{
	if (root == NULL) return 1;
	
	if (abs(getMaxDepth(root->left) - getMaxDepth(root->right)) <= 1 
        && IsValidAVL(root->left) && IsValidAVL(root->right))
		return 1;

	return 0;
}

void printInOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;

    // Print left branch
    printInOrderTree(root->left);

    // Print root
    printf("%d\n", root->data);

    // Print right branch
    printInOrderTree(root->right);
}