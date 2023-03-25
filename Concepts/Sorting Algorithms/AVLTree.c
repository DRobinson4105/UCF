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

// Find first node that has a balance factor that is greater than 1 or less than -1
Node * firstUnbalancedNode(Node * root);

// Get balance factor of a node
int getBalanceFactor(Node * root);

// Balances a BST, making it a valid AVL Tree
// Returns the new root of the BST
// (NOT FINISHED)
Node * AVLSort(Node * root);

// Perform a right rotation on a BST
Node * rightRotation(Node * root);

// Perform a left rotation on a BST
Node * leftRotation(Node * root);

int main()
{
    Node * root = NULL;
    for (int i = 0; i < 100; i++)
    {
        root = insertNode(root, rand() % 100);
    }

    printInOrderTree(root);

    if (IsValidAVL(root))
		printf("Valid AVL Tree\n");
	else
		printf("Not Valid AVL Tree\n");

    root = AVLSort(root);

    if (IsValidAVL(root))
		printf("Valid AVL Tree\n");
	else
		printf("Not Valid AVL Tree\n");

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
	
    // If every node is balanced
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

Node * firstUnbalancedNode(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return NULL;

    // If an unbalanced node was found in the left branch
    Node * left = firstUnbalancedNode(root->left);

    if (left != NULL)
        return left;

    // If an unbalanced node was found in the right branch
    Node * right = firstUnbalancedNode(root->right);

    if (right != NULL)
        return right;

    int maxLeft = getMaxDepth(root->left);
    int maxRight = getMaxDepth(root->right);

    // Calculate balance factor of root node and return the node if it is unbalanced
    return (maxLeft - maxRight > 1 || maxLeft - maxRight < -1) ? root : NULL; 
}

int getBalanceFactor(Node * root)
{
    if (root == NULL) return 0;

    return getMaxDepth(root->left) - getMaxDepth(root->right);
}

Node * AVLSort(Node * root)
{
    while(!IsValidAVL(root))
    {
        Node * unbalancedNode = firstUnbalancedNode(root);

        // Left Heavy
        if (getBalanceFactor(unbalancedNode) >= 2)
        {
            // Left Left Heavy
            if (getBalanceFactor(unbalancedNode->left) >= 1)
            {
                unbalancedNode = leftRotation(unbalancedNode);
            }

            // Left Right Heavy
            else
            {
                unbalancedNode->left = rightRotation(unbalancedNode->left);
                unbalancedNode = leftRotation(unbalancedNode);
            }
        }

        // Right Heavy
        else
        {
            // Right Left Heavy
            if (getBalanceFactor(unbalancedNode->left) <= -1)
            {
                unbalancedNode->right = leftRotation(unbalancedNode->right);
                unbalancedNode = rightRotation(unbalancedNode);
            }

            // Right Right Heavy
            else
            {
                unbalancedNode = rightRotation(unbalancedNode);
            }
        }
    }

    return root;
}

Node * rightRotation(Node * root)
{
    Node * rightChild = root->right;
    root->right = rightChild->left;
    rightChild->left = root;

    return rightChild;
}

Node * leftRotation(Node * root)
{
    Node * leftChild = root->left;
    root->left = leftChild->right;
    leftChild->right = root;

    return leftChild;
}