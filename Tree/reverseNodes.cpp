/* LC#25

Given the head of a linked list, 
reverse the nodes of the list k at a time, 
and return the modified list.

k is a positive integer and is less than or equal to 
the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes, in the end, 
should remain as it is.

You may not alter the values in the list's nodes, 
only nodes themselves may be changed.
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::vector<int> reverseVector (vector<int>& v, int k) {
	int i = 0;
	vector<int> tmp = {};
	vector<int> res = {};
	while (i < v.size()) {
		tmp.push_back(v[i]);
		i++;
		if (tmp.size() == k) {
			reverse(tmp.begin(), tmp.end());
			for (auto &j : tmp)
				res.push_back(j);
			tmp.clear();
		}
	}
	if (!tmp.empty()) {
		for (auto &j : tmp)
			res.push_back(j);
	}
	return res;
}

ListNode* reverseKGroup (ListNode* head, int k) {
	vector<int> v;
	unordered_map<int, ListNode*> nodes;
	while (head != nullptr) {
		nodes.insert({head->val, head});
		v.push_back(head->val);
		head = head->next;
	}
	vector<int> res = reverseVector(v, k);
	for (auto& i : res)
		cout << i << " ";
	cout << endl;
	
	for (int i = 0; i < res.size() - 1; i++) {
		nodes[res[i]]->next = nodes[res[i + 1]];
	}
	nodes[res[res.size() - 1]]->next = nullptr;
	return nodes[res[0]];
}

int main () {
	struct ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	struct ListNode* reversed_node = reverseKGroup (head, 2);

	while (reversed_node != nullptr) {
		cout << reversed_node->val << " ";
		reversed_node = reversed_node->next;
	}
	cout << endl;
	return 0;
}