#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
    int val;
    ListNode * next;
};

void addNode(ListNode * node, int value);

void printList(ListNode * node, int start);

void removeNode(ListNode * node, int index);

void insertNode(ListNode * node, int value, int index);

ListNode * reverseList(ListNode * node);

ListNode * initialize(int value);

void sortList(ListNode * head);

ListNode * merge(ListNode * left, ListNode * right);

int getSize(ListNode * head, int count);

ListNode * getNode(ListNode * head, int index);

ListNode * getNodes(ListNode * head, int start, int end);

int main()
{
    ListNode * head = NULL;

    head = initialize(5);
    addNode(head, 10);
    addNode(head, 3);
    addNode(head, 7);
    addNode(head, 1);
    addNode(head, 9);
    addNode(head, 6);
    addNode(head, 2);
    addNode(head, 8);
    addNode(head, 4);
    // printList(head, 1);
    // removeNode(head, 2);
    // printList(head, 1);
    // insertNode(head, 11, 2);
    // printList(head, 1);
    // printf("%d\n", getSize(head, 0));

    // ListNode * secondHead;
    // head = reverseList(head);
    // printList(head, 1);

    // printf("%d\n", getNode(head, 3)->val);

    // secondHead = getNodes(head, 1, 5);

    // printList(secondHead, 1);

    printList(head, 1);

    sortList(head);

    printList(head, 1);
}

ListNode * initialize(int value)
{
    ListNode * new = (ListNode *) malloc(sizeof(ListNode));
    new->val = value;
    return new;
}

void addNode(ListNode * node, int value)
{
    if(node == NULL)
    {
        printf("running\n");
        node = (ListNode *) malloc(sizeof(ListNode));
        node->val = value;
        node->next = NULL;
        printf("finished\n");
        return;
    }

    if(node->next == NULL)
    {
        ListNode * newNode = (ListNode *) malloc(sizeof(ListNode));
        newNode->val = value;
        node->next = newNode;
        return;
    }

    addNode(node->next, value);
}

void printList(ListNode * node, int start)
{
    if(start == 1) printf("[");
    if(node->next == NULL)
    {
        printf("%d]\n", node->val);
        return;
    }

    printf("%d, ", node->val);
    printList(node->next, 0);
}

void removeNode(ListNode * node, int index)
{
    if(index == 1)
    {
        node->next = node->next->next;
        return;
    }

    removeNode(node->next, index - 1);
}

void insertNode(ListNode * node, int value, int index)
{
    if(index == 1)
    {
        ListNode * new = (ListNode *) malloc(sizeof(ListNode));
        new->val = value;
        new->next = node->next;
        node->next = new;
        return;
    }

    insertNode(node->next, value, index - 1);
}

ListNode * reverseList(ListNode * node)
{
    ListNode * newNode = (ListNode *) malloc(sizeof(ListNode));

    newNode->val = node->val;
    // printf("Value: %d\n", newNode->val);

    if(node->next == NULL)
    {
        // toString(newNode, 1);
        return newNode;
    }
    
    ListNode * nextNode = reverseList(node->next);
    addNode(nextNode, newNode->val);
    return nextNode;
}

void sortList(ListNode * head)
{
    if(head->next != NULL)
    {
        int size = getSize(head, 0);
        int mid = size / 2;
        
        ListNode * left = getNodes(head, 0, mid);
        ListNode * right = getNodes(head, mid, size);
        sortList(left);
        sortList(right);

        *head = *merge(left, right);
    }
}

int getSize(ListNode * head, int count)
{
    if(head->next != NULL)
    {
        return getSize(head->next, count + 1);
    }
    return count + 1;
}

int get(ListNode * head, int index)
{
    if(index == 0)
    {
        return head->val;
    }
    return getNode(head->next, index - 1);
}

ListNode * getNodes(ListNode * head, int start, int end)
{
    if(start == 0)
    {
        ListNode * newHead = initialize(head->val);
        head = head->next;
        for(int i = 0; i < end - 1; i++)
        {
            addNode(newHead, head->val);
            head = head->next;
        }
        return newHead;
    }
    return getNodes(head->next, start - 1, end - 1);
}

ListNode * merge(ListNode * left, ListNode * right)
{
    if(left == NULL) return right;
    if(right == NULL) return left;
    ListNode * total;
    if(left->val < right->val)
    {
        total = initialize(left->val);
        left = left->next;
    }
    else
    {
        total = initialize(right->val);
        right = right->next;       
    }

    while(left != NULL && right != NULL)
    {
        if(left->val < right->val)
        {
            addNode(total, left->val);
            left = left->next;
        }
        else
        {
            addNode(total, right->val);
            right = right->next;
        }
    }

    while(left != NULL)
    {
        addNode(total, left->val);
        
        left = left->next;
    }

    while(right != NULL)
    {
        addNode(total, right->val);
        
        right = right->next;
    }

    return total;
}