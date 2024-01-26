/* LC#872

Consider all the leaves of a binary tree, 
from left to right order, 
the values of those leaves form a leaf value sequence.
*/

struct TreeNode {
	int val;
 	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// WRONG: dfs needed, not bfs traversal
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	vector<int> leaves1, leaves2;
	queue<TreeNode*> q; q.push(root1);
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		if (tmp->left == NULL && tmp->right == NULL)
			leaves1.push_back(tmp->val);
		if (tmp->left != NULL)	
			q.push(tmp->left);
		if (tmp->right != NULL)	
			q.push(tmp->right);
	}
	q.push(root2);
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		if (tmp->left == NULL && tmp->right == NULL)
			leaves2.push_back(tmp->val);
		if (tmp->left != NULL)	
			q.push(tmp->left);
		if (tmp->right != NULL)	
			q.push(tmp->right);
	}
	if (leaves1.size() != leaves2.size())
		return false;
	for (int i = 0; i < leaves1.size(); i++)
		if (leaves1[i] != leaves2[i])
			return false;
	return true;
}

void dfs (TreeNode* root, vector<int>& leaves) {
	if (root == NULL)
		return;
	else if (root->left == NULL && root->right == NULL)
		leaves.push_back(root->val);
	else {
		dfs(root->left);
		dfs(root->right);
	}
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	vector<int> leaves1, leaves2;
	dfs(root1, leaves1);
	dfs(root2, leaves2);
	if (leaves1.size() != leaves2.size())
		return false;
	for (int i = 0; i < leaves1.size(); i++)
		if (leaves1[i] != leaves2[i])
			return false;
	return true;
}