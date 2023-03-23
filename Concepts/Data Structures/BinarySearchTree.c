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

// Insert value into BST and return the new root of the BST
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

int getDepth(Node * root)
{
    if (root == NULL) return 0;

    int left = getDepth(root->left);
    int right = getDepth(root->right);

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
        // If the node has zero children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // If the node has one child
        if (root->left == NULL || root->right == NULL)
        {
            Node * temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;

            free(root);
            return temp;
        }

        // If the node has two children
        int direction;
        if (getDepth(root->left) > getDepth(root->right))
            direction = -1;
        else
            direction = 1;

        if (direction == 1)
        {
            Node * temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            temp->left = root->left;

            Node * newRoot = root->right;
            free(root);
            return newRoot;
        }
        else
        {
            Node * temp = root->left;

            while (temp->right != NULL)
                temp = temp->right;

            temp->right = root->right;

            Node * newRoot = root->left;
            free(root);
            return newRoot;
        }
    }
    else if (value < root->data)
        root->left = removeNode(root->left, value);
    else
        root->right = removeNode(root->right, value);

    return root;
}

int IsValidBST(Node * root)
{
	if (root == NULL) return 1;
	
	if (abs(getDepth(root->left) - getDepth(root->right)) <= 1 
		&& IsValidBST(root->left) && IsValidBST(root->right))
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

    printf("Depth: %d\n", getDepth(root));
	
	if (IsValidBST(root))
		printf("Valid BST\n");
	else
		printf("Not valid BST\n");

    root = removeNode(root, 5);
    root = removeNode(root, 2);
    root = removeNode(root, 6);
    printf("---In---\n");
    printInOrderTree(root);
    printf("---Post---\n");
    printPostOrderTree(root);
    printf("---Pre---\n");
    printPreOrderTree(root);

    printf("Depth: %d\n", getDepth(root));

	if (IsValidBST(root))
		printf("Valid BST\n");
	else
		printf("Not valid BST\n");

    return 0;
}