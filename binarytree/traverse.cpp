#include<iostream>
#include<vector>
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
	//前序遍历 
	void pretraversal(TreeNode* cur, vector<int>& a)
	{
		if (cur == NULL) return;
		a.push_back(cur->val);
		pretraversal(cur->left,a);
		pretraversal(cur->right, a);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		pretraversal(root, result);
		return result;
	}

	//中序遍历
	void intraversal(TreeNode* cur, vector<int>& a)
	{
		if (cur == NULL) return;
		intraversal(cur->left, a);
		a.push_back(cur->val);
		intraversal(cur->right, a);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		intraversal(root, result);
		return result;
	}
	//后序遍历
	void posttraversal(TreeNode* cur, vector<int>& a)
	{
		if (cur == NULL) return;
		posttraversal(cur->left, a);
		posttraversal(cur->right, a);
		a.push_back(cur->val);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		posttraversal(root, result);
		return result;
	}
};