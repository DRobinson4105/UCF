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
        while (head != nullptr && head->val == val)
            head = head->next;

        if (head == nullptr)
            return nullptr;

        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            while (curr->next != nullptr && curr->next->val == val)
                curr->next = curr->next->next;
            
            curr = curr->next;
        }

        return head;
    }
};