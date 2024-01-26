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

bool ancestry (Node* root, Node* child) {
	if (root == NULL)
		return false;
	else if (root == child)
		return true;
	return ancestry(root->left, child) || ancestry(root->right, child);
}

Node* lca_bt (Node* root, Node* left, Node* right) {
	if (ancestry(left, right))
		return left;
	else if (ancestry(right, left))
		return right;
	else if (ancestry(root->left, left) && ancestry(root->right, right))
		return root;
	else if (ancestry(root->left, left) && ancestry(root->left, right))
		return lca_bt(root->left, left, right);
	else if (ancestry(root->right, left) && ancestry(root->right, right))
		return lca_bt(root->right, left, right);
	return NULL;
}

/* LC#1650

Lowest Common Ancestor of a Binary Tree

Given two nodes of a binary tree p and q, 
return their lowest common ancestor (LCA).

According to the definition of LCA on Wikipedia: 
"The lowest common ancestor of two nodes p and q in a tree T 
is the lowest node that has both p and q as descendants 
(where we allow a node to be a descendant of itself)."

    3
   / \
  5   1
 / \ / \
6  2 0  8
  / \
 7   4
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
	int depth_p = get_depth(p), depth_q = get_depth(q);
	if (depth_p > depth_q)
		for (int i = 0; i < depth_p - depth_q; i++)
			p = p->parent;
	else if (depth_p < depth_q)
		for (int i = 0; i < depth_q - depth_p; i++)
			q = q->parent;
	if (p->val == q->val)
		return p;
	while (p->val != q->val) {
		p = p->parent;
		q = q->parent;
	}
	return p;
}

/*
	20
	/\
   8 22
  /  /\
 4  21 24

lca_bt(root, 21, 24) = 22
*/


/* LC#235

Given a binary search tree (BST), 
find the lowest common ancestor (LCA) 
node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between 
two nodes p and q as the lowest node in T 
that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
*/

struct TreeNode2 {
	int val;
	TreeNode2 *left, *right;
	TreeNode2(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode2* lowestCommonAncestor2
	(TreeNode2* root, TreeNode2* p, TreeNode2* q) {
		if (p->val > q->val)
			return lowestCommonAncestor2(root, q, p);
		if (root == NULL || root == p || root == q)
			return root;
		if (p->val < root->val && q->val > root->val)
			return root;
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor2(root->left, q, p);
		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor2(root->right, q, p);
		return NULL;
}

/* LC#236

Given a binary tree, find the lowest common ancestor 
(LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between 
two nodes p and q as the lowest node in T 
that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
*/


bool is_descendant (TreeNode2* root, TreeNode2* p) {
	if (root == NULL)
		return false;
  else if (root == p)
    return true;
	return is_descendant(root->left, p) 
		|| is_descendant(root->right, p);
}

TreeNode2* lowestCommonAncestor 
	(TreeNode2* root, TreeNode2* p, TreeNode2* q) {
		if (root == NULL)
			return NULL;
		if (root == p || root == q)
			return root;

		if (root->left != NULL
			&& is_descendant(root->left, p) 
			&& is_descendant(root->left, q))
			return lowestCommonAncestor(root->left, p, q);
		else if (root->right != NULL
			&& is_descendant(root->right, p) 
			&& is_descendant(root->right, q))
			return lowestCommonAncestor(root->right, p, q);
		else if (is_descendant(root->right, p) 
			&& is_descendant(root->left, q))
			return root;
		else if (is_descendant(root->left, p) 
			&& is_descendant(root->right, q))
			return root;
		return NULL;
}


int main() {
	Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->right->left = newNode(21);
	root->right->right = newNode(24);
	Node* ancestor = lca_bst (root, root->left->left, root->right->right);
	cout << ancestor->data << endl;

	Node* ancestor1 = lca_bt (root, root->right->left, root->right->right);
	cout << ancestor1->data << endl;

	TreeNode* newroot = new TreeNode();
	newroot->val = 3; newroot->parent = NULL;
	newroot->left = addNode(5, newroot);
	newroot->right = addNode(1, newroot);
	newroot->left->left = addNode(6, newroot->left);
	newroot->left->right = addNode(2, newroot->left);
	newroot->right->left = addNode(0, newroot->right);
	newroot->right->right = addNode(8, newroot->right);
	newroot->left->right->left = addNode(7, newroot->left->right);
	newroot->left->right->right = addNode(4, newroot->left->right);
	cout << lca(newroot->left, newroot->left->right->right)->val << endl;
	return 0;
}