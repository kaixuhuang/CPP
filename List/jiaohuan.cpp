#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode* vhead = new ListNode();
		vhead->next = head;
		ListNode* cur = NULL;
		ListNode* tmp1 = new ListNode();
		ListNode* tmp2 = new ListNode();
		cur = vhead;;
		while (cur->next != nullptr && cur->next->next != nullptr)
		{
			tmp2 = cur->next->next->next;
			tmp1 = cur->next;
			cur->next = cur->next->next;
			cur->next->next = tmp1;
			cur->next->next->next = tmp2;
			cur = cur->next->next;;

		}
		return vhead->next;

    }

};
