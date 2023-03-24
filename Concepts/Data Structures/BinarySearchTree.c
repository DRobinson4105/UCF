#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node * left;
    Node * right;
};

// Dynamically allocate memory for node, initializing it with the given value
// Return the pointer to that node
Node * createNode(int value);

// Insert value into BST and return the new root of the BST
Node * insertNode(Node * root, int value);

// Return the max depth of BST from the given root
int getMaxDepth(Node * root);

// Remove value from BST and return the new root of the BST
Node * removeNode(Node * root, int value);

// Check if BST is also an AVL Tree
int IsValidAVL(Node * root);

// Print BST in Post Order
void printPostOrderTree(Node * root);

// Print BST in order
void printInOrderTree(Node * root);

// Print BST in Pre Order
void printPreOrderTree(Node * root);

// Find lowest value node in BST
Node * minValueNode(Node * root);

// Find highest value node in BST
Node * maxValueNode(Node * root);

// Returns number of nodes in BST
int sizeofBST(Node * root);

// Store BST nodes into an array in order
void storeNodeValues(Node * root, int * nodes, int * size);

// Converts BST into a valid AVL Tree
Node * convertBSLtoAVL(Node * root);

// Builds a BST from an array recursively
Node * buildBSTFromArray(int start, int end, int * array);

// Frees all dynamic memory used for BST
void freeBST(Node * root);

int main()
{
    Node * root = NULL;
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 5);

    printf("---In---\n");
    printInOrderTree(root);
    printf("---Post---\n");
    printPostOrderTree(root);
    printf("---Pre---\n");
    printPreOrderTree(root);

    printf("Depth: %d\n", getMaxDepth(root));
    printf("Size: %d\n", sizeofBST(root));

	if (IsValidAVL(root))
		printf("Valid AVL Tree\n");
	else
		printf("Not Valid AVL Tree\n");

    root = convertBSLtoAVL(root);

	if (IsValidAVL(root))
		printf("Valid AVL Tree\n");
	else
		printf("Not Valid AVL Tree\n");

    root = removeNode(root, 5);
    root = removeNode(root, 2);
    root = removeNode(root, 6);
    printf("---In---\n");
    printInOrderTree(root);
    printf("---Post---\n");
    printPostOrderTree(root);
    printf("---Pre---\n");
    printPreOrderTree(root);

    printf("Depth: %d\n", getMaxDepth(root));
    printf("Size: %d\n", sizeofBST(root));

	if (IsValidAVL(root))
		printf("Valid AVL Tree\n");
	else
		printf("Not Valid AVL Tree\n");

    freeBST(root);

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

Node * removeNode(Node * root, int value)
{
    // Node was not found
    if (root == NULL) return NULL;

    // If the node was found
    if (root->data == value)
    {
        // If the node has zero children or only a right child
        if (root->left == NULL)
        {
            // Replace node with right child
            Node * temp = root->right;
            free(root);
            return temp;
        }

        // If the node only has a left child
        else if (root->right == NULL)
        {
            // Replace node with left child
            Node * temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children

        // Find which branch has the higher depth
        // Find closest value to root in that branch and replace the root with it
        Node * temp;

        if (getMaxDepth(root->left) > getMaxDepth(root->right))
        {
            temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = removeNode(root->left, temp->data);
        }
        else
        {
            temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
    }

    // If value is in left branch
    else if (value < root->data)
        root->left = removeNode(root->left, value);

    // If value is in right branch
    else
        root->right = removeNode(root->right, value);

    return root;
}

int IsValidAVL(Node * root)
{
	if (root == NULL) return 1;
	
	if (abs(getMaxDepth(root->left) - getMaxDepth(root->right)) <= 1 
        && IsValidAVL(root->left) && IsValidAVL(root->right))
		return 1;

	return 0;
}

void printPostOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;

    // Print left branch
    printPostOrderTree(root->left);

    // Print right branch
    printPostOrderTree(root->right);

    // Print root
    printf("%d\n", root->data);
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

void printPreOrderTree(Node * root)
{
    // Reached end of a branch
    if (root == NULL) return;

    // Print root
    printf("%d\n", root->data);

    // Print left branch
    printInOrderTree(root->left);

    // Print right branch
    printInOrderTree(root->right);
}

Node * minValueNode(Node * root)
{
    if (root->left == NULL)
        return root;
    
    return minValueNode(root->left);
}

Node * maxValueNode(Node * root)
{
    if (root->right == NULL)
        return root;
    
    return maxValueNode(root->right);
}

int sizeofBST(Node * root)
{
    if (root == NULL) return 0;

    return 1 + sizeofBST(root->left) + sizeofBST(root->right);
}

void storeNodeValues(Node * root, int * nodes, int * size)
{
    // Reached end of branch
    if (root == NULL) return;

    // Store all values in left branch
    storeNodeValues(root->left, nodes, size);

    // Store root value
    nodes[*size] = root->data;
    (*size)++;

    // Store all values in right branch
    storeNodeValues(root->right, nodes, size);
}

Node * convertBSLtoAVL(Node * root)
{
    int size = 0;
    int * nodes = (int *) malloc(sizeof(int) * sizeofBST(root));   

    // Store all nodes from the BST into an array
    storeNodeValues(root, nodes, &size);

    // Build a balanced BST from the array
    Node * newRoot = buildBSTFromArray(0, size - 1, nodes);

    // Free the array
    free(nodes);

    // Return root to the new balanced BST
    return newRoot;
}

Node * buildBSTFromArray(int start, int end, int * array)
{
    if (start > end) return NULL;

    // Middle value in given subarray to use as next root
    int mid = (end + start) / 2;
    Node * root = createNode(array[mid]);

    // Repeat process for left and right branches using left and right halfs of the subarray
    root->left = buildBSTFromArray(start, mid - 1, array);
    root->right = buildBSTFromArray(mid + 1, end, array);

    // Return root of the balanced BST
    return root;
}

void freeBST(Node * root)
{
    if (root == NULL) return;

    freeBST(root->left);
    freeBST(root->right);

    free(root);
}