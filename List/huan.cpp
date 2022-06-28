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
	ListNode* detectCycle(ListNode* head) {
		ListNode *cur = new ListNode();
		ListNode* begin = head;
		int pos = 0;
		cur = head;
		if (head == NULL)
			return NULL;
		while (true)
		{
			if (cur->next == NULL)
				return NULL;
			else
			{
				cur = cur->next;
				begin = head;
				int x = pos++;
				while (x--)
				{
					if (cur->next == begin)
						goto x;
					begin = begin->next;
				}
				
			}
		}
	x:return begin;
		
	}
};
