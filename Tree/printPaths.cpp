#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right; // Alternatively, struct Node* left, *right;
	Node (int data) {
		this->data = data;
		left = right = NULL;
	} 
};

void Paths (struct Node* node, int path[], int len) {
	if (node == NULL)
		return;
	path[len] = node->data; len++;
	if (node->left == NULL && node->right == NULL) {
		for (int i = 0; i < len; i++)
			cout << path[i] << " ";
		cout << endl;
	}
	else {
		Paths (node->left, path, len);
		Paths (node->right, path, len);
	}
}

int main() {
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->left->right = new Node(5);
	int path[100];
	Paths(root, path, 0);
	return 0;
}