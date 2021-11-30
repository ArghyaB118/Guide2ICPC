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

void invertTree(TreeNode* root) {
	if (!root)
		return;
	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left)
		invertTree(root->left);
	if (root->right)
		invertTree(root->right);
}

void PreOrder(TreeNode* node) {
	if (node == NULL)
		return;
	cout << node->val << " ";
	PreOrder(node->left); PreOrder(node->right);
}

int main() {
	struct TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	PreOrder(root); cout << endl; invertTree(root); PreOrder(root);
	return 0;
}