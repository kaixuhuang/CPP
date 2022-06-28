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
    ListNode* reverseList(ListNode* head) {
		if (!head)
			return {};
		else {
			ListNode* l = NULL;
			ListNode* r = new ListNode();
			ListNode* tmp = new ListNode();
			
			r = head;
			while (r)
			{
				tmp = r->next;
				r->next = l;
				l = r;
				r = tmp;
			}
			return l;
		}
    }

};
//int main()
//{
//	ListNode* head = new ListNode();
//	ListNode* l1 = new ListNode(2);
//	ListNode* l2 = new ListNode(6);
//	ListNode* l3 = new ListNode(3);
//	ListNode* l4 = new ListNode(4);
//	ListNode* l5 = new ListNode(5);
//	ListNode* l6 = new ListNode(6);
//	head->next = l1;
//	l1->next = l2;
//	l2->next = l3;
//	l3->next = l4;
//	l4->next = l5;
//	l5->next = l6;
//
//	Solution A;
//	head =A.reverseList(head);
//
//		while (head)
//	{
//		cout << head->val << endl;
//		head = head->next;
//	}
//}