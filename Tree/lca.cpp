// lowest common ancestor in a binary search tree
// BST = max(left subtree) < node < min(right subtree) V all nodes
// LCA is a node farthest from the root

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node* newNode(int data);
};

Node* newNode (int data) {
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node; 
}

Node* lca (Node* root, Node* left, Node* right) {
	if (root == NULL || left == NULL || right == NULL)
		return NULL;
	else if (root->data > left->data && root->data > right->data)
		lca (root->left, left, right);
	else if (root->data < left->data && root->data < right->data)
		lca (root->right, left, right);
	return root;
}

int main() {
	Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->right->right = newNode(24);
	Node* ancestor = lca (root, root->left->left, root->right->right);
	cout << ancestor->data << endl;
	return 0;
}