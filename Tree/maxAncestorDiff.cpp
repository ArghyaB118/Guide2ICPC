/* LC#1026

Given the root of a binary tree, 
find the maximum value v for which there exist 
different nodes a and b where v = |a.val - b.val| 
and a is an ancestor of b.

A node a is an ancestor of b if either: 
any child of a is equal to b or any child of a is an ancestor of b.

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 10^5
*/

typedef pair<int, int> maxMin;
#define max_val 100000

maxMin getMaxMin (TreeNode* node, int& max_diff) {
	if (node == NULL)
		return {max_val, 0};
	if (!node->left && !node->right)
		return {node->val, node->val};
	if (node->left)
		maxMin m1 = getMaxMin (node->left, max_diff);
	if (node->right)
		maxMin m2 = getMaxMin (node->right, max_diff);
	int min_val = min(min(m1.first, m2.first), node->val);
	int max_val = max(max(m1.first, m2.first), node->val);
	max_diff = max(max(max_diff, abs(node->val - min_val)), 
		abs(max_val, node->val));
	return {min_val, max_val};
}

int maxAncestorDiff(TreeNode* root) {
	int max_diff = 0;
	getMaxMin (root);
}