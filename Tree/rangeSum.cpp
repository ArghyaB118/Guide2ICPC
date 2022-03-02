#include <iostream>
#include <vector>
using namespace std;

struct node {
	int val;
	node *left, *right;
	node (int x) {
		this->val = x;
		this->left = this->right = nullptr;
	}
};

int rangeSum (node *root, int low, int high) {
	if (root == NULL)
		return 0;
	if (root->val > high) {
		if (root->left != NULL)
			return rangeSum (root->left, low, high);
		else
			return 0;
	}
	else if (root->val < low) {
		if (root->right != NULL)
			return rangeSum (root->right, low, high);
		else
			return 0;
	}
	if (root->left == NULL && root->right == NULL)
		return root->val;
	else if (root->left == NULL && root->right != NULL)
		return root->val + rangeSum (root->right, low, high);
	else if (root->left != NULL && root->right == NULL)
		return root->val + rangeSum (root->left, low, high);
	return root->val + rangeSum (root->left, low, high) + rangeSum (root->right, low, high);
}

int main () {
	struct node *root = new node(10);
	root->left = new node(5);
	root->right = new node(15);
	root->left->left = new node(3);
	root->left->right = new node(7);
	root->right->right = new node(18);
	cout << "The sum of elements between 7 and 15: " << rangeSum(root, 7, 15) << endl;
	return 0;
}