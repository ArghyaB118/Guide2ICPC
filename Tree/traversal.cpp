#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right; // Alternatively, struct Node* left, *right;
	Node (int data) {
		this->data = data;
		left = right = NULL;
	} 
};

// left, right, root
// T(n) = T(k) + T(n - k -1); cost = O(n)
void PostOrder (struct Node* node) {
	if (node == NULL)
		return;
	PostOrder(node->left); PostOrder(node->right);
	cout << node->data << " ";
}


// root, left, right
void PreOrder (struct Node* node) {
	if (node == NULL)
		return;
	cout << node->data << " ";
	PreOrder(node->left); PreOrder(node->right);
}

// left, root, right
void InOrder (struct Node* node) {
	if (node == NULL)
		return;
	InOrder(node->left);
	cout << node->data << " ";
	InOrder(node->right);
}

// depth of a tree
int depth (struct Node* node) {
	if (node == NULL)
		return 0;
	else {
		int ldepth = depth(node->left);
		int rdepth = depth(node->right);
		return ((ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1));
	}
}

// level order traversal
void Level (struct Node* root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		Level (root->left, level - 1);
		Level (root->right, level - 1);
	}
}
void LevelOrder (struct Node* root) {
	int h = depth(root);
	for (int i = 1; i <= h; i++)
		Level (root, i);
}

// level order traversal using a queue
void LevelOrderQueue (struct Node* root) {
	if (root == NULL)
		return;
	queue<Node*> q; q.push(root);
	while (!q.empty()) {
		Node* node = q.front(); q.pop();
		if (node->left != NULL)
			q.push(node->left); 
		if (node->right != NULL) 
			q.push(node->right);
		cout << node->data << " ";
	}
}

int main() {
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	PostOrder(root); cout << endl; 
	PreOrder(root); cout << endl; 
	InOrder(root); cout << endl; 
	LevelOrder(root); cout << endl;
	LevelOrderQueue(root); cout << endl;
	return 0;
}