#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> closestNodeUtil (TreeNode* root, int query) {
    int left = -1, right = -1;
    if (root == NULL)
        return {left, right};
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->val >= query) {
            if (right != -1)
                right = min(right, node->val);
            else
                right = node->val;
            if (node->left)
                q.push(node->left);
        }
        if (node->val <= query) {
            if (left != -1)
                left = max(left, node->val);
            else
                left = node->val;
            if (node->right)
                q.push(node->right);
        }
        if (left == query && right == query)
            return {left, right};
    }
    return {left, right};
}

vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<vector<int>> result = {};
    // cout << root->val << endl;
    for (auto & query : queries) {
        result.push_back(closestNodeUtil (root, query));
    }
    // cout << root->val << endl;
    return result;
}

int main () {
    
}
