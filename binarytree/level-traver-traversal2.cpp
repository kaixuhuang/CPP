#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//116
class Solution {
public:
    Node* connect(Node* root) {
		Node* start = root;
		queue<Node*> que;
		if (root != NULL)
			que.push(root);
		Node* cur;
		int size, i;
		while (!que.empty()) {
			size = que.size();
			vector<int> tmp;
			for (i = 0; i < size; i++)
			{
				cur = que.front();
				que.pop();
				if (i < size - 1)
					cur->next = que.front();
				tmp.push_back(cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			
		}
		return root;

    }
	//117

};