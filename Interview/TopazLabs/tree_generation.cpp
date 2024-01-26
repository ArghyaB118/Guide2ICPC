#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

struct Node {
	int val;
	Node* parent;
	vector<Node*> children;

	Node(int val_) {
		val = val_;
		children = vector<Node*> {};
	};
};

int generateRandomValue () {
	srand(time(0));
	return rand();
}

unordered_set<int> values_used;

Node* buildTree (int n, int k) {
	struct Node* head = new Node(generateRandomValue());
	values_used.insert(head->val);
	if (n == 1)
		return head;
	queue<Node*> curr_level, next_level;
	curr_level.push(head);
	for (int i = 0; i < n - 1; i++) {
		// cout << i << " " << curr_level.size() << " " << next_level.size() << endl;
		while (!curr_level.empty()) {
			int number_children = rand() % (k - 1) + 2;
			for (int j = 0; j < number_children; j++) {
				int val_ = generateRandomValue();
				while (values_used.find(val_) != values_used.end())
					val_ = generateRandomValue();
				struct Node* node = new Node(val_);
				values_used.insert(val_);
				node->parent = curr_level.front();
				curr_level.front()->children.push_back(node);
				next_level.push(node);
			}
			curr_level.pop();
		}
		// cout << next_level.size() << endl;
		while(!next_level.empty()) {
			curr_level.push(next_level.front());
			next_level.pop();
		}
	}
	return head;
}

void printTree (Node* head) {
	queue<Node*> q;
	q.push(head);
	while (!q.empty()) {
		cout << q.front()->val << endl;
		for (auto &i : q.front()->children)
			q.push(i);
		q.pop();
	}
}

int main () {
	Node* head = buildTree(3, 3);
	printTree(head);
	return 0;
}