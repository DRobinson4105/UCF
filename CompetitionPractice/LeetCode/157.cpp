#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int aLen = 0, bLen = 0;
		ListNode * tempA = headA;
		ListNode * tempB = headB;

		while (tempA != NULL) {
			aLen++;
			tempA = tempA -> next;
		}

		while (tempB != NULL) {
			bLen++;
			tempB = tempB -> next;
		}

		int diff;

		if (aLen > bLen) {
			diff = aLen - bLen;

			while (diff) {
				headA = headA -> next;
				diff--;
			}
		}

		else {
			diff = bLen - aLen;
			
			while (diff) {
				headB = headB -> next;
				diff--;
			}
		}

		while (headA && headB) {
			if(headA == headB)
				return headA;

			headA = headA -> next;
			headB = headB -> next;
		}
		
		return NULL;
	}
};