/* LC#958

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
*/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCompleteTree (TreeNode* root) {
	if (root == NULL)
		return true;
	queue<TreeNode*> q;
	q.push(root);
	bool endCall = false;
	while (!q.empty()) {
		TreeNode* tmp = q.front(); q.pop();
		if (tmp == NULL && !endCall)
			endCall = true;
		else if (tmp && endCall)
			return false;
		else if (!endCall && tmp->left && tmp->right) {
			q.push(tmp->left);
			q.push(tmp->right);
		}
		else if (!endCall && !tmp->left && tmp->right)
			return false;
		else if (!endCall && tmp->left && !tmp->right) {
			q.push(tmp->left);
			q.push(NULL);
		}
		else if (!endCall && !tmp->left && !tmp->right) {
			q.push(NULL);
			q.push(NULL);
		}
	}
	return true;
}