/*
Use a slow and fast pointer to traverse through the linked list
since the pointers will be equal at some point if there is a cycle

1. Start slow pointer at first node and fast pointer at second node
2. While neither pointer has reached the end of the list
    - If the pointers are pointing to same node, return true
    - If fast pointer has reached the end, return false
    - Move fast pointer down 2 nodes
    - Move slow pointer down 1 node
3. Return false since end of list was found
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;

        while (slow && fast)
        {
            // If fast pointer has looped around and is
            // pointing to same node as slow pointer
            if (slow == fast)
                return true;

            // If end of list was reached
            if (!fast->next)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};