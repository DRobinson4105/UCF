#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* createNode(int val)
    {
        ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
        newNode->val = val;
        newNode->next = nullptr;

        return newNode;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode * newList;
        if (list1->val < list2->val)
        {
            newList = createNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            newList = createNode(list2->val);
            list2 = list2->next;
        }
        
        ListNode * newHead = newList;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                newList->next = createNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                newList->next = createNode(list2->val);
                list2 = list2->next;
            }

            newList = newList->next;
        }

        while (list1)
        {
            newList->next = createNode(list1->val);
            list1 = list1->next;
            newList = newList->next;
        }

        while (list2)
        {
            newList->next = createNode(list2->val);
            list2 = list2->next;
            newList = newList->next;
        }

        return newHead;
    }
};