#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Example Tree
//		1
//		/\
//	2		3
//	/\		/\
//4		5


struct Node {
	int data;
	struct Node *left, *right; // Alternatively, struct Node* left, *right;
	Node (int data) {
		this->data = data;
		left = right = NULL;
	} 
};

// left, right, root
// 4 5 2 3 1
// T(n) = T(k) + T(n - k -1); cost = O(n)
void PostOrder (struct Node* node) {
	if (node == NULL)
		return;
	PostOrder(node->left); PostOrder(node->right);
	cout << node->data << " ";
}


// root, left, right
// 1 2 4 5 3
void PreOrder (struct Node* node) {
	if (node == NULL)
		return;
	cout << node->data << " ";
	PreOrder(node->left); PreOrder(node->right);
}

// left, root, right
// 4 2 5 1 3
void InOrder (struct Node* node) {
	if (node == NULL)
		return;
	InOrder(node->left);
	cout << node->data << " ";
	InOrder(node->right);
}

// depth of a tree
int depth (struct Node* node) {
	if (node == NULL)
		return 0;
	else {
		int ldepth = depth(node->left);
		int rdepth = depth(node->right);
		return ((ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1));
	}
}

// level order traversal
// 1 2 3 4 5
void Level (struct Node* root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		Level (root->left, level - 1);
		Level (root->right, level - 1);
	}
}

// Same as BFS on Tree -- O(n)
void LevelOrder (struct Node* root) {
	int h = depth(root);
	for (int i = 1; i <= h; i++)
		Level (root, i);
}

// level order traversal using a queue
void LevelOrderQueue (struct Node* root) {
	if (root == NULL)
		return;
	queue<Node*> q; q.push(root);
	while (!q.empty()) {
		Node* node = q.front(); q.pop();
		if (node->left != NULL)
			q.push(node->left); 
		if (node->right != NULL) 
			q.push(node->right);
		cout << node->data << " ";
	}
}

typedef pair<int, struct Node*> Pair;

vector<vector<int>> verticalOrder (struct Node* root) {
	vector<vector<int>> result;
	map<int, vector<int>> elements;
	queue<Pair> nodes; nodes.push(make_pair(0, root));
	while (!nodes.empty()) {
		Pair root = nodes.front();
		elements[root.first].push_back(root.second->data);
		nodes.pop();
		if (root.second->left != NULL) {
			nodes.push(make_pair(root.first - 1, root.second->left));
		}
		if (root.second->right != NULL)
			nodes.push(make_pair(root.first + 1, root.second->right));
	}
	for (auto & m : elements)
		result.push_back(m.second);
	return result;
}


Node* array2LevelOrderTree (int arr[], Node* root, int l, int r) {
	if (l < r) {
		Node* temp = new Node(arr[l]);
		root = temp;
		root->left = array2LevelOrderTree (arr, root->left, 2*l + 1, r);
		root->right = array2LevelOrderTree (arr, root->right, 2*l + 2, r);
	}
	return root;
}

//Node* array2InPreOrderTree (int arr_preorder[], int arr_inorder[]) {

//}

int main() {
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	PostOrder(root); cout << endl; 
	PreOrder(root); cout << endl; 
	InOrder(root); cout << endl; 
	LevelOrder(root); cout << endl;
	LevelOrderQueue(root); cout << endl;

	int arr[] = {1, 2, 3, 4, 5}; int n = sizeof(arr) / sizeof(arr[0]);
	struct Node* new_root = array2LevelOrderTree (arr, new_root, 0, n);
	LevelOrder(new_root); cout << endl;

	int arr_preorder[] = {1, 2, 4, 5, 3};
	int arr_inorder[] = {4, 2, 5, 1, 3};
//	struct Node* root = array2InPreOrderTree(arr_inorder, arr_preorder);
	LevelOrder(new_root); cout << endl;

	for (int i = 0; i < verticalOrder(root).size(); i++) {
		for (int j = 0; j < verticalOrder(root)[i].size(); j++)
			cout << verticalOrder(root)[i][j] << " ";
		cout << endl;
	}
	return 0;
}