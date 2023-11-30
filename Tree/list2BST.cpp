/* LC#109

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Constraints:
The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool verbose = true;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBSTUtil(vector<int> list, int start, int end) {
	if (start > end)
		return NULL;
	else if (start == end) {
		TreeNode* node = new TreeNode(list[start]);
		return node;
	}
	else if (start + 1 == end) {
		TreeNode* node1 = new TreeNode(list[end]);
		TreeNode* node2 = new TreeNode(list[start]);
		node1->left = node2;
		return node1;
	}
	else if (start + 2 == end) {
		TreeNode* node1 = new TreeNode(list[(start + end) / 2]);
		TreeNode* node2 = new TreeNode(list[start]);
		TreeNode* node3 = new TreeNode(list[end]);
		node1->left = node2;
		node1->right = node3;
		return node1;
	}
	TreeNode* node = new TreeNode(list[(start + end) / 2]);
	if (verbose)
		cout << node->val << endl;
	node->left = sortedListToBSTUtil(list, start, (start + end) / 2 - 1);
	node->right = sortedListToBSTUtil(list, (start + end) / 2 + 1, end);
	return node;
}

TreeNode* sortedListToBST(ListNode* head) {
	vector<int> list;
	while (head) {
		list.push_back(head->val);
		head = head->next;
	}
	if (verbose) {
		for (auto & i : list)
			cout << i << " ";
		cout << endl;
	}
	if (list.size() == 0)
		return NULL;
	int n = list.size();
	if (verbose)
		cout << n << endl;
	TreeNode* root = sortedListToBSTUtil (list, 0, n - 1);
	return root;
}

void levelOrder (TreeNode* root) {
	cout << "Level Order Traversal:" << endl;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		cout << q.front()->val << " ";
		if (q.front()->left)
			q.push(q.front()->left);
		if (q.front()->right)
			q.push(q.front()->right);
		q.pop();
	}
	cout << endl;
}

int main () {
	ListNode* head = new ListNode(-10);
	head->next = new ListNode(-3);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(5);
	head->next->next->next->next = new ListNode(9);
	TreeNode* root = sortedListToBST(head);
	levelOrder (root);
	return 0;
}