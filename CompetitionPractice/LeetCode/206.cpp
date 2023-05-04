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
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode* old = head;
        ListNode* curr = head->next;
        while (head->next != nullptr) {
            head->next = curr->next;
            curr->next = old;

            old = curr;
            curr = head->next;
        }

        return old;
    }
};