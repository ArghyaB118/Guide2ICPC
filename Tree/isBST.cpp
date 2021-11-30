#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
	Node (int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

// max(left subtree) < node < min(right subtree) V all nodes
bool isBST (struct Node* root, struct Node* l, struct Node* r) {
	if (root == NULL)
		return true;
	if (l != NULL && root->data <= l->data)
		return false;
	if (r != NULL && root->data >= r->data)
		return false;
	return isBST (root->left,l,root) && isBST (root->right, root, r);
}

int main() {
	struct Node *root = new Node(30);
	root->left = new Node(20);
	root->right = new Node(50);
	root->left->left = new Node(10);
	root->left->right = new Node(50);
	cout << boolalpha << isBST(root, NULL, NULL) << endl;
	return 0;
}