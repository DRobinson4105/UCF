/*
Start with a sublist being the first node and repeatedly
move the next node to the head of the sublist

1. Keep a pointer to front of sublist and end of sublist
2. While there is still nodes that are not in the sublist
    - Save pointer to next node in list as curr
    - Have end of sublist point to the node after curr
    - Move curr to front of sublist
3. Return sublist head
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* old = head;
        ListNode* curr = head->next;

        while (head->next != nullptr) {
            // Have end of sublist point to node after curr
            head->next = curr->next;
            curr->next = old;

            // Move curr to front of sublist
            old = curr;
            curr = head->next;
        }

        return old;
    }
};