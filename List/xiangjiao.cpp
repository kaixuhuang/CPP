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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		int countA = 0;
		int countB = 0;
		int cut = 0;
		while (p1)
		{
			p1 = p1->next;
			countA++;
		}
		while (p2)
		{
			p2 = p2->next;
			countB++;
		}
		p1 = headA;
		p2 = headB;
		if (countA >= countB && countA !=0 && countB !=0)
		{
			cut = countA - countB;
			while(cut>0) {
				p1 = p1->next;
				cut--;
			}
			while (p1 != NULL)
			{
				if (p1 == p2)
					break;
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
		else if (countA < countB && countA != 0 && countB != 0)
		{
			cut = countB - countA;
			while (cut > 0) {
				p2 = p2->next;
				cut--;
			}
			while ( p1!=NULL)
			{
				if (p1 == p2)
					break;
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
		return NULL;

	}
};
//int main()
//{
//	Solution A;
//	ListNode* headA = new ListNode(4);
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(8);
//	ListNode* l3 = new ListNode(4);
//	ListNode* l4 = new ListNode(5);
//	headA->next = l1;
//	l1->next = l2;
//	l2->next = l3;
//	l3->next = l4;
//	ListNode* headB = new ListNode(5);
//	ListNode* X1 = new ListNode(0);
//	ListNode* X2 = new ListNode(1);
//	headB->next = X1;
//	X1->next = X2;
//	X2->next = l2;
//	ListNode* newhead = A.getIntersectionNode(headA, headB);
//	cin.get();
//
//
//	
//
//
//
//
//}