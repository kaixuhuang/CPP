#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
//二叉树的统一迭代法
class Solution {
public:
	//中序 
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> result;
		TreeNode* cur;
		if (root != NULL)
			stk.push(root);
		while (!stk.empty()){
			cur = stk.top();
			if (cur != NULL)
			{
				stk.pop();
				if (cur->right)
					stk.push(cur->right);
				stk.push(cur);
				stk.push(NULL);
				if (cur->left)
					stk.push(cur->left);
			}
			else
			{
				stk.pop();
				cur = stk.top();
				stk.pop();
				result.push_back(cur->val);
			}
		}
		return result;
	}
	//前序
	
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> result;
		TreeNode* cur;
		if (root != NULL)
			stk.push(root);
		while (!stk.empty()) {
			cur = stk.top();
			if (cur != NULL)
			{
				stk.pop();
				if (cur->right)
					stk.push(cur->right);
				if (cur->left)
					stk.push(cur->left);
				stk.push(cur);
				stk.push(NULL);
				
			}
			else
			{
				stk.pop();
				cur = stk.top();
				stk.pop();
				result.push_back(cur->val);
			}
		}
		return result;
	}

	//后序
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> result;
		TreeNode* cur;
		if (root != NULL)
			stk.push(root);
		while (!stk.empty()) {
			cur = stk.top();
			if (cur != NULL)
			{
				stk.pop();
				stk.push(cur);
				stk.push(NULL);
				if (cur->right)
					stk.push(cur->right);
				if (cur->left)
					stk.push(cur->left);
			}
			else
			{
				stk.pop();
				cur = stk.top();
				stk.pop();
				result.push_back(cur->val);
			}
		}
		return result;
	}
};