/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor 
and successor pointers in a doubly-linked list. 
For a circular doubly linked list, the predecessor of the first element 
is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, 
the left pointer of the tree node should point to its predecessor, 
and the right pointer should point to its successor. 
You should return the pointer to the smallest element of the linked list.

Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]

Input: root = [2,1,3]
Output: [1,2,3]
*/
#include <iostream>
using namespace std;

class Node {
private:
	int data;
public:
	Node *left, *right;
	Node (int data) {
		this->data = data;
		this->left = this->right = NULL;
	}

	Node (int data, Node* left, Node* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

Node* treeToDoublyList(Node* root) {
	
}

int main () {
	Node *root = new Node(4);
	root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
	return 0;
}