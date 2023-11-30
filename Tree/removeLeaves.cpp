/* LC#366
 
 Given the root of a binary tree, collect a tree's nodes as if you were doing this:
 
 Collect all the leaf nodes.
 Remove all the leaf nodes.
 Repeat until the tree is empty.
 
 Input: root = [1,2,3,4,5]
 Output: [[4,5,3],[2],[1]]*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> leaves (TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> v;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tmpNode = q.front(); q.pop();
        if (tmpNode->left) {
            if (tmpNode->left->left == NULL && tmpNode->left->right == NULL) {
                v.push_back(tmpNode->left->val);
                tmpNode->left = NULL;
            }
            else
                q.push(tmpNode->left);
        }
        if (tmpNode->right) {
            if (tmpNode->right->left == NULL && tmpNode->right->right == NULL) {
                v.push_back(tmpNode->right->val);
                tmpNode->right = NULL;
            }
            else
                q.push(tmpNode->right);
        }
    }
    return v;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    if (root == NULL)
        return {{}};
    vector<vector<int>> result;
    while (root->left != NULL || root->right != NULL) {
        result.push_back(leaves(root));
    }
    result.push_back({root->val});
    return result;
}

int main () {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> result = findLeaves(root);
    for (auto i : result) {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
