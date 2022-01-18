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

Node* lca_bst (Node* root, Node* left, Node* right) {
	if (root == NULL || left == NULL || right == NULL)
		return NULL;
	else if (root->data > left->data && root->data > right->data)
		lca_bst (root->left, left, right);
	else if (root->data < left->data && root->data < right->data)
		lca_bst (root->right, left, right);
	return root;
}

/*
Lowest Common Ancestor of a Binary Tree

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

According to the definition of LCA on Wikipedia: 
"The lowest common ancestor of two nodes p and q in a tree T 
is the lowest node that has both p and q as descendants 
(where we allow a node to be a descendant of itself)."
*/
class TreeNode {
public:
	int val;
	TreeNode *left, *right, *parent;
};

TreeNode* addNode(int data, TreeNode* parent) {
	TreeNode* treenode = new TreeNode();
	treenode->val = data;
	treenode->left = treenode->right = NULL;
	treenode->parent = parent;
	return treenode;
}

int get_depth(TreeNode* p) {
	int count = 0;
	while(p->parent != NULL) {
		p = p->parent;
		count++;
	}
	return count;
}

TreeNode* lca (TreeNode* p, TreeNode* q) {
	if (get_depth(p) > get_depth(q))
		for (int i = 0; i < get_depth(p) - get_depth(q); i++)
			p = p->parent;
	else if (get_depth(p) < get_depth(q))
		for (int i = 0; i < get_depth(q) - get_depth(p); i++)
			q = q->parent;
	while (p->val != q->val) {
		p = p->parent;
		q = q->parent;
	}
	return p;
}

int main() {
	Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->right->right = newNode(24);
	Node* ancestor = lca_bst (root, root->left->left, root->right->right);
	cout << ancestor->data << endl;


	TreeNode* newroot = new TreeNode();
	newroot->val = 3; newroot->parent = NULL;
	newroot->left = addNode(5, newroot);
	newroot->right = addNode(1, newroot);
	cout << lca(newroot->left, newroot->right)->val << endl;
	return 0;
}