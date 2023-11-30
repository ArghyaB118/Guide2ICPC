/* LC#142
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
Follow up: Can you solve it using O(1) (i.e. constant) memory?

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Repitition of value is not allowed
ListNode *detectCycle(ListNode *head) {
	unordered_set<int> s;
	while (head != NULL) {
		if (s.find(head->val) != s.end())
			return head;
		s.insert(head->val);
		head = head->next;
	}
	return NULL;
}

// Repitition of value is allowed
ListNode *detectCycle2(ListNode *head) {
	unordered_set<ListNode*> s;
	while (head != NULL) {
		if (s.find(head) != s.end())
			return head;
		s.insert(head);
		head = head->next;
	}
	return NULL;
}

// Two pointers: FLoyd's algorithm
// need more work
ListNode *detectCycle2Ptr(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return slow;
	}
	return NULL;
}

int main () {
	ListNode *head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	head->next->next->next->next = head->next;
	if (detectCycle2Ptr(head) != NULL)
		cout << detectCycle2Ptr(head)->val << endl;
	else
		cout << -1 << endl;
	return 0;
}