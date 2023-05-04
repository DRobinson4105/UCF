/*
Since linked list is sorted, all duplicate elements will be consecutive
For each set of two nodes, remove the second node if the two nodes are equal

1. While there is a next node in the list:
    - If the current node and next node are equal, remove the next node
    - Otherwise, traverse to next node
2. Return the head of the list
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr) return nullptr;

        ListNode* cur = head;

        while (cur && cur->next) {
            // Remove next node if curr node and next node are equal
            if(cur->next->val == cur->val)
                cur->next = (cur->next->next == nullptr) ? nullptr: cur->next->next;
            else
                cur = cur->next;
        }

        return head;
    }
};