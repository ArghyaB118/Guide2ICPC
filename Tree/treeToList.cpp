// tree to double linked list
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
};

int main () {
	Node *root = new Node(20);
	root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);
	return 0;
}