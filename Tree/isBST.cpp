#include <iostream>
#include <vector>
#include <queue>
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


/*
Balancing a Binary Tree to Binary Search Tree (BST)

Idea: Inorder traversal + building tree level order
*/

void inOrder (struct Node *root, vector<int>& v) {
	if (root == NULL)
		return;
	inOrder(root->left, v);
	v.push_back(root->data);
	inOrder(root->right, v);
}

Node* buildTree (vector<int>& v, int left, int right) {
	if (left < right)
		return NULL;
	int mid = left + (right - left) / 2;
	Node *node = new Node(v[mid]);
	node->left = buildTree(v, left, mid - 1);
	node->right = buildTree(v, mid + 1, right);
	return node;
}


void printLevelOrder (struct Node *root) {
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
	struct Node *root = new Node(30);
	root->left = new Node(20);
	root->right = new Node(50);
	root->left->left = new Node(10);
	root->left->right = new Node(55);
	cout << boolalpha << isBST(root, NULL, NULL) << endl;


	vector<int> v; inOrder(root, v);
//	for (auto & u : v)
//		cout << u << " ";
	struct Node* head; head = buildTree(v, 0, v.size());
	printLevelOrder(head);
	return 0;
}