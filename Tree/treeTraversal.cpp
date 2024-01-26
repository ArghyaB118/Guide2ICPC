#include <iostream>
#include <queue>
#include <map>
#include <vector>
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
// Note: Time complexity for any tree traversal = O(n)
// Space complexity = O(h) = O(log n) for DFS
//					= O(ceil(n / 2)) for BFS (in the worst-case)
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

/* LC#987

Vertical Order Traversal of a Binary Tree
    1
   / \
  2   3
 /\   /\
4  6 5  7

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be 
at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of 
top-to-bottom orderings for each column index starting from the 
leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. 

Option 1:
If two nodes are in the same row and column, the order should be from left to right.

Option 2 (difficult):
In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
*/


typedef pair<int, struct Node*> Pair;

vector<vector<int>> verticalOrder (struct Node* root) {
	if (root == NULL)
		return {};
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
	for (auto & m : elements) {
//		sort(m.second.begin(), m.second.end());
		result.push_back(m.second);
	}
	return result;
}

// beats 100% LC users
vector<vector<int>> verticalOrder2(TreeNode* root) {
    if (root == NULL)
	    return {};
    TreeNode* tmp = root;
    int max_depth = 0, min_depth = 0;
    queue<Pair> nodes; nodes.push(make_pair(0, tmp));
    while (!nodes.empty()) {
        Pair root = nodes.front();
        min_depth = min(min_depth, root.first);
        max_depth = max(max_depth, root.first);
	    nodes.pop();
        if (root.second->left != NULL) {
            nodes.push(make_pair(root.first - 1, root.second->left));
        }
        if (root.second->right != NULL)
            nodes.push(make_pair(root.first + 1, root.second->right));
    }
    vector<vector<int>> result(max_depth - min_depth + 1, vector<int>{});
    
    nodes.push(make_pair(0, root));
    while (!nodes.empty()) {
        Pair root = nodes.front();
        result[root.first - min_depth].push_back(root.second->val);
        nodes.pop();
        if (root.second->left != NULL) {
            nodes.push(make_pair(root.first - 1, root.second->left));
        }
        if (root.second->right != NULL)
            nodes.push(make_pair(root.first + 1, root.second->right));
    }
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

/* LC#543

Given the root of a binary tree, 
return the length of the diameter of the tree.

The diameter of a binary tree is the length 
of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes 
is represented by the number of edges between them.

Input: root = [1,2,3,4,5]
Output: 3

Input: root = [1,2]
Output: 1
*/

int diameter (struct Node* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 0;
	if (root->left == NULL)
		return max(depth(root->right), diameter(root->right));
	if (root->right == NULL)
		return max(depth(root->left), diameter(root->left));
	return (diameter(root->left) > diameter(root->right)) 
			? max(diameter(root->left), depth(root->left) + depth(root->right))
			: max(diameter(root->right), depth(root->left) + depth(root->right));
}

/* LC#199

Given the root of a binary tree, 
imagine yourself standing on the right side of it, 
return the values of the nodes you can see 
ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

// beats 65% LC users
vector<int> rightSideView(TreeNode* root) {
	vector<int> right_projection;
	if (!root) { return right_projection; }
	queue<TreeNode*> curr, next;
	curr.push(root);
	while (!curr.empty()) {
		TreeNode* node = curr.front();
		if (curr.size() == 1)
			right_projection.push_back(node->val);
		curr.pop();
		if (node->left) { next.push(node->left); }
		if (node->right) { next.push(node->right); }
		if (curr.empty()) { swap(curr, next); }
	}
	return right_projection;
}

// WRONG! root = [1,2,3,4] expected = [1,3,4] output = [1, 3]
vector<int> rightSideView2 (struct Node* root) {
	vector<int> v;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* root = q.front();
		v.push_back(root->data);
		q.pop();
		if (root->right != NULL) {
			q.push(root->right);
			root = root->right;
		}
		else if (root->right == NULL && root->left != NULL) {
			q.push(root->left);
			root = root->left;
		}
	}
	return v;
}

/* LC#103

Zigzag order traversal of a tree:
    1
   / \
  2   3
 /\   /\
4  5 6  7
	   / \
	  8   9

Output: 1, 3, 2, 4, 5, 6, 7, 9, 8
*/

vector<int> zigzagOrder (struct Node* root) {
	vector<vector<int>> traversal;
	queue<Pair> q; q.push(make_pair(0, root));
	int d = depth(root);
	for (int i = 0; i < d; i++)
		traversal.push_back({});
	while (!q.empty()) {
		Pair p = q.front();
		q.pop();
		traversal[p.first].push_back(p.second->data);
		if (p.second->left)	
			q.push(make_pair(p.first + 1, p.second->left));
		if (p.second->right)
			q.push(make_pair(p.first + 1, p.second->right));
	}
	vector<int> result;
	bool reverse = false;
	for (int i = 0; i < traversal.size(); i++) {
		if (!reverse) {
			reverse = true;
			for (int j = 0; j < traversal[i].size(); j++)
				result.push_back(traversal[i][j]);
		}
		else {
			reverse = false;
			for (int j = traversal[i].size() - 1; j >= 0; j--)
				result.push_back(traversal[i][j]);
		}
	}
	return result;
}

int main() {
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
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


	vector<vector<int>> result = verticalOrder(root);
	cout << "Vertical Order Traversal: ";
	for (int i = 0; i < result.size(); i++) {
		cout << "{";
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << ",";
		cout << "}";
	}
	cout << endl;

	cout << "The diameter of the tree: " << diameter(root) << endl;
	
	vector<int> v = rightSideView(root);
	for (int & vv : v)
		cout << vv << " ";
	cout << endl;

	root->right->right->left = new Node(8);
	root->right->right->right = new Node(9);
	vector<int> zigzag = zigzagOrder(root);
	cout << "The zigzag order traversal is: ";
	for (int & z : zigzag)
		cout << z << " ";
	cout << endl;
	return 0;
}
