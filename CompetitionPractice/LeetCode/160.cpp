/*
Check each possible intersection by starting heads off at first possible intersections
and traversing through lists until interesection is found or end of list was reached

1. Get the length of the linked lists by counting the number of nodes in each list
2. Remove head of longer linked list until both lists have the same length
3. Compare each set of nodes in each list, returning true if any set of nodes are equal
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode *headB) {
		int aLen = 0;
		int bLen = 0;

		// Get length of linked lists
		ListNode* temp = headA;
		while (temp != nullptr) {
			aLen++;
			temp = temp->next;
		}
		
		temp = headB;
		while (temp != nullptr) {
			bLen++;
			temp = temp->next;
		}

		// If one of the lists is longer than the other, traverse head in longer 
		// list until number of remaining nodes in both lists are the same
		while (aLen < bLen) {
			headB = headB->next;
			aLen++;
		}

		while (bLen < aLen) {
			headA = headA->next;
			bLen++;
		}

		// Traverse through lists and compare each set of
		// nodes until lists intersect or end of list is reached
		while (headA && headB) {
			if (headA == headB) {
				return headA;
			}

			headA = headA->next;
			headB = headB->next;
		}

		return nullptr;
	}
};