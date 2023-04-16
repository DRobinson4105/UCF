#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
Compare heads of lists to repeatedly add the lowest value to the sorted list

1. Create a new linked list to merge the two lists
2. Repeatedly move the lower head between list1 to list2
to new list until one of the linked lists is empty
3. Add any remaining values in list1 to new list
4. Add any remaining values in list2 to new list
*/

class Solution {
public:    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If either of the lists are empty
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode * newList;

        // Add lowest value to new list
        if (list1->val < list2->val) {
            newList = new ListNode(list1->val);
            list1 = list1->next;
        }
        else {
            newList = new ListNode(list2->val);
            list2 = list2->next;
        }
        
        // Save head of new list to return after merge
        ListNode * newHead = newList;

        // While neither list is empty, add lower head to new list
        while (list1 && list2)
        {
            if (list1->val < list2->val) {
                newList->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                newList->next = new ListNode(list2->val);
                list2 = list2->next;
            }

            newList = newList->next;
        }

        // Add any remaining values in list1 to new list
        while (list1) {
            newList->next = new ListNode(list1->val);
            list1 = list1->next;
            newList = newList->next;
        }

        // Add any remaining values in list2 to new list
        while (list2) {
            newList->next = new ListNode(list2->val);
            list2 = list2->next;
            newList = newList->next;
        }

        // Return head of new list
        return newHead;
    }
};