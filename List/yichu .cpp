#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* newhead = new ListNode();
		ListNode* Next = new ListNode();
		newhead->next = head;
		Next = newhead;
		while (Next->next!= NULL)
		{
			
			if (Next->next->val == val)

				Next->next = Next->next->next;
			else
				Next = Next->next;
				
			
		}
		return newhead->next;


	}
};
//int main()
//{
//	Solution A;
//	ListNode* head = new ListNode();
//	//ListNode* l1 = new ListNode(2);
//	//ListNode* l2 = new ListNode(6);
//	//ListNode* l3 = new ListNode(3);
//	//ListNode* l4 = new ListNode(4);
//	//ListNode* l5 = new ListNode(5);
//	//ListNode* l6 = new ListNode(6);
//	//head->next = l1;
//	//l1->next = l2;
//	//l2->next = l3;
//	//l3->next = l4;
//	//l4->next = l5;
//	//l5->next = l6;
//	ListNode* newhead = new ListNode();
//
//	newhead = A.removeElements(head, 1);
//	while (head)
//	{
//		cout << head->val << endl;
//		head = head->next;
//	}
//
//
//
//
//}