#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
	Node* head_copy = new Node(head->val);
	head_copy->next = 
	return head;
}

int main () {
	Node* root = new Node(1);
	root->next = new Node(2);
	root->next->next = new Node(3);
	root->random = root->next->next;
	root->next->random = root->next->next;
	root->next->next->random = root;
	return 0;
}