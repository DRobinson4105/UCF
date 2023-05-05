/*
Traverse through list removing any nodes that have the target value

1. Repeatedly remove head if it equals the target value until it doesn't
2. Loop through list, removing the next node if its value is the target value
3. Return head
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
    ListNode* removeElements(ListNode* head, int val) {
        // Repeatedly remove head if it equals the target value until it doesn't
        while (head != nullptr && head->val == val)
            head = head->next;

        // If list is now empty
        if (head == nullptr)
            return nullptr;

        ListNode* curr = head;
        
        // While curr has not reached end of list
        while (curr != nullptr && curr->next != nullptr) {

            // If next node is val, remove it
            while (curr->next != nullptr && curr->next->val == val)
                curr->next = curr->next->next;
            
            curr = curr->next;
        }

        return head;
    }
};