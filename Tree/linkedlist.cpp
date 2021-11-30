#include <iostream>
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

int main() {
	struct ListNode *head = new ListNode(1);
	head = push(&head, 2);
	head = push(&head, 3);
	push2(&head, 4);
	printList(head); deleteNode(head); printList(head);
	return 0;
}