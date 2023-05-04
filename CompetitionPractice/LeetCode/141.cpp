#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;

        while (slow && fast)
        {
            if (slow == fast)
                return true;

            if (!fast->next)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};