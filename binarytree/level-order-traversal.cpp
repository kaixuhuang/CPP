#include<iostream>
#include<queue>
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
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
class Solution {
public:
	//≤„–Ú±È¿˙
	/*vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		queue<TreeNode*> que;
		if (root != NULL)
			que.push(root);
		TreeNode* cur;
		int size,i;
		while (!que.empty()) {
			size = que.size();
			vector<int> tmp;
				for (i = 0; i < size; i++)
				{
					cur = que.front();
					que.pop();
					tmp.push_back(cur->val);
					if (cur->left)
						que.push(cur->left);
					if (cur->right)
						que.push(cur->right);
				}
				result.push_back(tmp);
		}
		return result;
	}*/
	//≤„–Ú±È¿˙µ›πÈ∑®
	void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
		if (cur == NULL) return;
		if (result.size() == depth) 
			result.push_back(vector<int>());
		result[depth].push_back(cur->val);
		order(cur->left, result, depth + 1);
		order(cur->right, result, depth + 1);


	}

      vector<vector<int>> levelOrder(TreeNode* root) {
		  vector<vector<int>> result;
		  int depth = 0;
		  order(root, result, depth);
		  return result;
	  
	  }
	  //107
	  vector<vector<int>> levelOrderBottom(TreeNode* root) {
		  vector<vector<int>> result;
		  vector<int> tmp;
		  queue<TreeNode*> que;
		  TreeNode* cur;
		  int size,i;
		  if (root == NULL)
		  return result;
		  que.push(root);
		  while (!que.empty())
		  {
			  size = que.size();
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  tmp.push_back(cur->val);
				  if (cur->left)
					  que.push(cur->left);
				  if (cur->right)
					  que.push(cur->right);
			  }
			  result.push_back(tmp);
			  tmp.clear();
		  }
		  reverse(result.begin(), result.end());
		  return result;
	  }
	  //199
	  vector<int> rightSideView(TreeNode* root) {
		  vector<int> result;
		  queue<TreeNode*> que;
		  TreeNode* cur;
		  int size, i;
		  if (root == NULL)
		  return result;
		  que.push(root);
		  while (!que.empty())
		  {
			  size = que.size();
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  if(i==size-1)
				     result.push_back(cur->val);
				  if (cur->left)
					  que.push(cur->left);
				  if (cur->right)
					  que.push(cur->right);
			  }
		  }
		  return result;
	  }
	  //637
	  vector<double> averageOfLevels(TreeNode* root) {
		  vector<double> result;
		  queue<TreeNode*> que;
		  TreeNode* cur;
		  int size, i;
		  double sum;
		  if (root == NULL)
			  return result;
		  que.push(root);
		  while (!que.empty())
		  {
			  sum = 0;
			  size = que.size();
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  sum += cur->val;
				  if (cur->left)
					  que.push(cur->left);
				  if (cur->right)
					  que.push(cur->right);
			  }
			  result.push_back(sum / size);
		  }
		  return result;
	  }

	  //429
	  vector<vector<int>> levelOrder(Node* root) {
		  vector<vector<int>> result;
		  vector<int> tmp;
		  queue<Node*> que;
		  Node* cur;
		  int size, i,j;
		  if (root == NULL)
			  return result;
		  que.push(root);
		  while (!que.empty())
		  {
			  size = que.size();
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  tmp.push_back(cur->val);
				  for (j = 0; j < cur->children.size(); j++)
				  {
					  if (cur->children[j])
						  que.push(cur->children[j]);
				  }
			  }
			  result.push_back(tmp);
			  tmp.clear();
		  }
		  return result;
	  }

	  //515

	  vector<int> largestValues(TreeNode* root) {
		  vector<int> result;
		  queue<TreeNode*> que;
		  TreeNode* cur;
		  int size, i;
		  int max;
		  if (root == NULL)
			  return result;
		  que.push(root);
		  while (!que.empty())
		  {
			  max = que.front()->val;
			  size = que.size();
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  if (max < cur->val)
					  max = cur->val;
				  if (cur->left)
					  que.push(cur->left);
				  if (cur->right)
					  que.push(cur->right);
			  }
			  result.push_back(max);
		  }
		  return result;
	  }
	  //104
	  int maxDepth(TreeNode* root) {
		  int result =0;
		  queue<TreeNode*> que;
		  if (root != NULL)
			  que.push(root);
		  TreeNode* cur;
		  int size, i;
		  while (!que.empty()) {
			  size = que.size();
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  if (cur->left)
					  que.push(cur->left);
				  if (cur->right)
					  que.push(cur->right);
			  }
			  result++;
		  }
		  return result;
	  }
	  //111
	  int minDepth(TreeNode* root) {
		  int result = 0;
		  queue<TreeNode*> que;
		  if (root != NULL)
			  que.push(root);
		  TreeNode* cur;
		  int size, i;
		  while (!que.empty()) {
			  size = que.size();
			  result++;
			  for (i = 0; i < size; i++)
			  {
				  cur = que.front();
				  que.pop();
				  if (cur->left == NULL && cur->right == NULL)
					  return result;
				  if (cur->left)
					  que.push(cur->left);
				  if (cur->right)
					  que.push(cur->right);
			  }

		  }
		  return result;
	  }
};