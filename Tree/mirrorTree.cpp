#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left = NULL, *right = NULL;
	struct Node* newNode (int data);
};

struct Node* newNode (int data) {
	struct Node* node = (struct Node*) malloc (sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node; 
}

void mirror (struct Node* node) {
	if (node == NULL)
		return;
	else {
		struct Node* temp = NULL;
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

void inOrder (struct Node* root) {
	if (root == NULL)
		return;
	inOrder (root->left);
	cout << root->data << " ";
	inOrder (root->right);
}

int main() {
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	inOrder (root); cout << endl;
	mirror (root);
	inOrder (root); cout << endl;
	return 0;
}