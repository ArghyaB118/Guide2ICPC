/* LC#2385

You are given the root of a binary tree with unique values, 
and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

The number of nodes in the tree is in the range [1, 10^5].
1 <= Node.val <= 10^5.
*/

#include <iostream>
#include <vector>
using namespace std;

int amountOfTime(TreeNode* root, int start) {
	int node_count = 0;
	queue<TreeNode*> q;
	unordered_map<int, vector<int>> 
	q.push(root);
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		if (tmp->left) { }
	}
}