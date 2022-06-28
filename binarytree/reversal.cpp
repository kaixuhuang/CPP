#include<iostream>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

}; 
class Solution {
public:
	//226-µÝ¹é 
	//void traversal(TreeNode* cur)
	//{
	//	if (cur == NULL)
	//		return;
	//	TreeNode* tmp = cur->left;
	//	cur->left = cur->right;
	//	cur->right = tmp;
	//	traversal(cur->left);
	//	traversal(cur->right);
	//}
	//TreeNode* invertTree(TreeNode* root) {
	//	traversal(root);
	//	return root;
	//}
	//226-µü´ú
	//TreeNode* invertTree(TreeNode* root) {
	//	stack<TreeNode*> stk;
	//	if (root == NULL)
	//	return root;
	//	stk.push(root);
	//	TreeNode* cur;
	//	while (!stk.empty())
	//	{
	//		cur = stk.top();
	//		stk.pop();
	//		swap(cur->left, cur->right);
	//		if (cur->right)
	//			stk.push(cur->right);
	//		if (cur->left)
	//			stk.push(cur->left);
	//		
	//	}
	//	return root;
	//}
	//226 -²ãÐò
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		queue<TreeNode*> que;
		int size, i;
		TreeNode* cur;
		que.push(root);
		while (!que.empty())
		{
			
			size = que.size();
			for (i = 0; i < size; i++)
			{
				cur = que.front();
				que.pop();
				swap(cur->left, cur->right);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
		}
		return root;

	}
};