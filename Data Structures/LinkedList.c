#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
    int val;
    ListNode * next;
};

// Adds node with given value at the end of the linked list
// head --> head of linked list
void appendNode(ListNode * head, int value);

// Prints linked list with brackets as [n1, n2, ...]
// node --> head->next (first node of linked list)
void printList(ListNode * node);

// Removes node at given index
// node --> head->next (first node of linked list)
void removeNode(ListNode * head, int index);

// Adds node with given value at the given index
// node --> head->next (first node of linked list)
void insertNode(ListNode * node, int value, int index);

// Reverse order of nodes
// node --> head->next (first node of linked list)
ListNode * reversedList(ListNode * node);

// Repeatedly splits linked list until each linked list only
// has one node and then merges and sorts the linked lists
// node --> head->next (first node of linked list)
void sortList(ListNode * node);

// Merges and sorts two linked lists of elements
ListNode * merge(ListNode * left, ListNode * right);

// Returns size of linked list by recursively traversing
// through the linked list adding one for every node
// node --> head->next (first node of linked list)
int getSize(ListNode * node);

// Get the value of a specific node
// node --> head->next (first node of linked list)
ListNode * getNode(ListNode * node, int index);

// Get a new linked list that is the indexes [start..end-1]
// of the given linked list
// node --> head->next (first node of linked list)
ListNode * getNodes(ListNode * node, int start, int end);

// Free memory for linked list
void freeList(ListNode * head);

int main()
{
    ListNode * head = (ListNode *) malloc(sizeof(ListNode));

    // Linked List: {5, 10, 11, 7, 1, 9, 6, 2, 8, 4}
    //     Indexes:  0   1   2  3  4  5  6  7  8  9
    appendNode(head, 5);
    appendNode(head, 10);
    appendNode(head, 11);
    appendNode(head, 7);
    appendNode(head, 1);
    appendNode(head, 9);
    appendNode(head, 6);
    appendNode(head, 2);
    appendNode(head, 8);
    appendNode(head, 4);

    printList(head->next);

    // Remove element at index of 2 in the linked list which is 11
    // Linked List: {5, 10, 7, 1, 9, 6, 2, 8, 4}
    //     Indexes:  0   1  2  3  4  5  6  7  8
    removeNode(head->next, 2);
    printList(head->next);

    // Insert 3 at the index of 5 so it is between 9 and 6
    // Linked List: {5, 10, 7, 1, 9, 3, 6, 2, 8, 4}
    //     Indexes:  0   1  2  3  4  5  6  7  8  9
    insertNode(head, 3, 5);
    printList(head->next);

    // Size: 10
    printf("Size: %d\n", getSize(head->next));
    
    // Get subset of linked list of indexes 1 through 5
    // Linked List: {10, 7, 1, 9, 3}
    //     Indexes:      0  1  2  3  4
    ListNode * secondHead = (ListNode *) malloc(sizeof(ListNode));
    secondHead->next = getNodes(head->next, 1, 5);
    printList(secondHead->next);
    printf("Size: %d\n", getSize(secondHead->next));

    // Reversed order of nodes
    // Linked List: {4, 8, 2, 6, 3, 9, 1, 7, 10, 5}
    //     Indexes:  0  1  2  3  4  5  6  7   8  9
    head->next = reversedList(head->next);
    printList(head->next);

    // Sort linked list
    // Linked List: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    //     Indexes:  0  1  2  3  4  5  6  7  8   9
    sortList(head->next);
    printList(head->next);

    // Get node at 4th index of linked list which has a value of 5
    // Linked List: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    //     Indexes:  0  1  2  3 (4)  5  6  7  8   9
    printf("list[4] = %d\n", getNode(head->next, 4)->val);

    // Free linked lists from memory
    freeList(head);
    freeList(secondHead);

    return 0;
}

void appendNode(ListNode * head, int value)
{
    // When the function finds the last node in the list
    if(head->next == NULL)
    {
        // Adds node with the given value to the end
        ListNode * newNode = (ListNode *) malloc(sizeof(ListNode));
        newNode->val = value;
        head->next = newNode;
        return;
    }

    appendNode(head->next, value);
}

void printList(ListNode * node)
{
    printf("[");

    // Print nodes
    while(node)
    {
        if(node->next == NULL)
        {
            // Print [ after the last node
            printf("%d", node->val);
            break;
        }

        // Commas between nodes
        printf("%d, ", node->val);

        node = node->next;
    }

    printf("]\n");
}

void removeNode(ListNode * node, int index)
{
    // Once target node is found, replace it with the next node
    if(index == 0)
    {
        ListNode * nextNode = node->next;
        *node = *nextNode;
        return;
    }

    // Move to next node
    removeNode(node->next, index - 1);
}

void insertNode(ListNode * node, int value, int index)
{
    // Once target index is found
    if(index == 0 || node->next == NULL)
    {
        // Insert the value before the current node
        ListNode * new = (ListNode *) malloc(sizeof(ListNode));
        new->val = value;
        new->next = node->next;
        node->next = new;
        return;
    }

    // Move to next node
    insertNode(node->next, value, index - 1);
}

ListNode * reversedList(ListNode * node)
{
    // Return last node to be first node of reversed list
    if(node->next == NULL)
    {
        ListNode * lastNode = (ListNode *) malloc(sizeof(ListNode));
        lastNode->val = node->val;
        return lastNode;
    }

    // Add each value in the reverse order
    ListNode * nextNode = reversedList(node->next);
    appendNode(nextNode, node->val);
    
    // Return first node
    return nextNode;
}

int getSize(ListNode * node)
{
    if(node == NULL) return 0;

    // Add one for every node
    if(node->next == NULL) return 1;

    return getSize(node->next) + 1;
}

ListNode * getNode(ListNode * node, int index)
{
    // Return the node when node is the correct index in the list
    if(index == 0)
        return node;

    return getNode(node->next, index - 1);
}

ListNode * getNodes(ListNode * node, int start, int end)
{
    // Once start of sublist has been found
    if(start == 0)
    {
        // Create head for new list
        ListNode * newHead = (ListNode *) malloc(sizeof(ListNode));
        
        // Add every value from start to end
        for(int i = 0; i <= end; i++)
        {
            appendNode(newHead, node->val);
            node = node->next;
        }

        // Return values without blank head
        return newHead->next;
    }

    // Move to next node in list
    return getNodes(node->next, start - 1, end - 1);
}

void sortList(ListNode * node)
{
    // If empty list was entered
    if(node == NULL) return;
    
    if(node->next != NULL)
    {
        int size = getSize(node);
        int mid = size / 2;
        
        // Sort left and right halves of list
        ListNode * left = getNodes(node, 0, mid - 1);
        ListNode * right = getNodes(node, mid, size - 1);
        sortList(left);
        sortList(right);

        // Merge both halves together
        *node = *merge(left, right);

        // Free both halves from memory
        freeList(left);
        freeList(right);
    }
}

ListNode * merge(ListNode * left, ListNode * right)
{
    // Skip process if left or right is empty
    if(left == NULL) return right;
    if(right == NULL) return left;

    // Create temp linked list to merge left and right lists
    ListNode * total = (ListNode *) malloc(sizeof(ListNode));

    // Merge and sort all values until either node has reached end of its list
    while(left != NULL && right != NULL)
    {
        if(left->val < right->val)
        {
            appendNode(total, left->val);
            left = left->next;
        }
        else
        {
            appendNode(total, right->val);
            right = right->next;
        }
    }

    // Copy any remaining elements in the left list
    while(left != NULL)
    {
        appendNode(total, left->val);
        left = left->next;
    }

    // Copy any remaining elements in the right list
    while(right != NULL)
    {
        appendNode(total, right->val);
        right = right->next;
    }

    // Return merged list without blank head
    return total->next;
}

void freeList(ListNode * head)
{
    // If list is empty
    if(head == NULL) return;

    // Free last node
    if(head->next == NULL)
    {
        free(head);
        return;
    }

    // Free nodes in reverse order
    freeList(head->next);
    free(head);
}
