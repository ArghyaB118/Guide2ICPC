#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node (int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

int leafCount (struct Node* root) {
	if (root == NULL)
		return 0;
	if (!root->left && !root->right)
		return 1;
	else
		return (leafCount(root->left) + leafCount(root->right));
}


int main() {
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	cout << "The number of leaves: " << leafCount(root) << endl;
}