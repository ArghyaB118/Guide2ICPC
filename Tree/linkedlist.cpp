#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() {
		this->val = 0;
		this->next = NULL;
	}
	ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode* push(struct ListNode **head, int val) {
	struct ListNode *node = new ListNode(val);
	node->next = *head;
	return node;
}

void push2(struct ListNode **head, int val) {
	struct ListNode *node = new ListNode();
	node->val = val;
	node->next = *head;
	*head = node;
}

void printList(ListNode *head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void deleteNode(ListNode* node) {
    while (node->next != NULL) {
        node->val = node->next->val;
        if (node->next->next != NULL)
            node = node->next;
        else
            node->next = NULL;
    }
}


/*
You are given a singly-linked list that contains N integers. 
A subpart of the list is a contiguous set of even elements, 
bordered either by either end of the list or an odd element. 
For example, if the list is [1, 2, 8, 9, 12, 16], 
the subparts of the list are [2, 8] and [12, 16].

Then, for each subpart, the order of the elements is reversed. 
In the example, this would result in the new list, [1, 8, 2, 9, 16, 12].
The goal of this question is: given a resulting list, 
determine the original order of the elements.
*/

void appendNode (ListNode *head, int val) {
	while (head->next != NULL) 
		head = head->next;
	struct ListNode *node = new ListNode(val);
	head->next = node;
	node->next = NULL;
}

struct ListNode* reverse (ListNode* Node) {
	struct ListNode *head = new ListNode(Node->val);
	stack<int> st;
	while (Node->next != NULL) {
		Node = Node->next;
		if (Node->val % 2 != 0) {
			if (st.empty())
				appendNode(head, Node->val);
			else {
				while (!st.empty()) {
					appendNode(head, st.top());
					st.pop();
				}
				appendNode(head, Node->val);
			}
		}
		else
			st.push(Node->val);
	}
	return head;
}


int main() {
	struct ListNode *head = new ListNode(1);
	head = push(&head, 2);
	head = push(&head, 3);
	push2(&head, 4);
	printList(head); deleteNode(head); printList(head);

	head = reverse(head); printList(head);
	return 0;
}