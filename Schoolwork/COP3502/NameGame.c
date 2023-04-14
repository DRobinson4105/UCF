#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 21

typedef struct Node Node;

struct Node {
    int value; // Value at node
    int subTreeFlag; // Count of insertions in subtree
    Node * children[26]; // 26 children for 26 letters
};

Node * createNode();
Node * insertNode(Node * root, char * str, int value);
int countNames(Node * root, char * prefix);
void renameNode(Node * root, char * old, char * new);
int removeNode(Node * root, char * str);
void freeTrie(Node * root);

int main()
{
    int numOrangutans, numEvents;
    int option, value;
    char oldStr[MAX_STRING_LEN], newStr[MAX_STRING_LEN];
    Node * root;

    scanf("%d %d", &numOrangutans, &numEvents);
    for (int i = 0; i < numEvents; i++)
    {
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                scanf(" %s %d", newStr, &value);
                root = insertNode(root, newStr, value);
                break;

            case 2:
                scanf(" %s %s", oldStr, newStr);
                renameNode(root, oldStr, newStr);
                break;

            case 3:
                scanf(" %s", newStr);
                printf("%d\n", countNames(root, newStr));
                break;
        }
    }

    return 0;
}

Node * createNode()
{
    Node * node = (Node *) malloc(sizeof(Node));

    // Node is
    node->value = -1;
    node->subTreeFlag = 0;

    // Set child pointers
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;

    return node;
}

Node * insertNode(Node * root, char * str, int value)
{
    if (root == NULL)
        root = createNode();

    // Loop to end of string
    Node * cur = root;
    int index;

    while (str[0] != '\0')
    {
        // Find the child index based on the letter
        int index = str[0] - 'A';

        // Create the child if it does not exist
        if (cur->children[index] == NULL)
            cur->children[index] = createNode();

        cur->subTreeFlag += value;

        // Try moving to next child
        cur = cur->children[index];

        str++;
    }

    // At location to insert value
    cur->subTreeFlag += value;
    cur->value = value;

    // Return the resulting root
    return root;
}

int removeNode(Node * root, char * str)
{
    if (root == NULL)
        return 0;

    if (str[0] == '\0')
    {
        int removedValue = root->value;
        root->value = 0;
        root->subTreeFlag -= removedValue;
        return removedValue;
    }
    
    int index = str[0] - 'A';
    str++;
    int removedValue = removeNode(root->children[index], str);
    root->subTreeFlag -= removedValue;
    return removedValue;
}
int countNames(Node * root, char * prefix)
{
    if (root == NULL) return 0;
    
    Node * cur = root;
    int index;

    while (prefix[0] != '\0')
    {
        // Find the child index based on the letter
        int index = prefix[0] - 'A';

        // Create the child if it does not exist
        if (cur->children[index] == NULL)
            return 0;

        // Try moving to next child
        cur = cur->children[index];

        prefix++;
    }

    return cur->subTreeFlag;
}

void renameNode(Node * root, char * old, char * new)
{
    if (root == NULL) return;
    
    int val = removeNode(root, old);

    insertNode(root, new, val);
}

void freeTrie(Node * root)
{
    if (root == NULL) return;

    for (int i = 0; i < 26; i++)
        freeTrie(root->children[i]);

    free(root);
}