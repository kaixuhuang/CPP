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

class Solution {
public:
	//«∞–Ú
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> result;
		if (root == NULL)
			return result;
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			result.push_back(cur->val);
			stk.pop();
			if (cur->right)
				stk.push(cur->right);
			if (cur->left)
				stk.push(cur->left);
		}
		return result;
	}
	//÷––Ú
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> result;
		TreeNode* cur = root;
		while (cur != NULL || !stk.empty())
		{
			if (cur != NULL){
				stk.push(cur);
				cur = cur->left;

			}
			else{
				cur = stk.top();
				stk.pop();
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;
	}
	//∫Û–Ú
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> stk;
		vector<int> result;
		if (root == NULL)
			return result;
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			result.push_back(cur->val);
			stk.pop();
			if (cur->right)
				stk.push(cur->left);
			if (cur->left)
				stk.push(cur->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};