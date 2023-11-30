/* LC#2096
 You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string root2leafPath (TreeNode* root, int value) {
    queue<TreeNode*> nodes;
    queue<string> paths;
    nodes.push(root); paths.push("");
    while (!nodes.empty()) {
        if (nodes.front()->val == value) return paths.front();
        else {
            if (nodes.front()->left != NULL) {
                nodes.push(nodes.front()->left);
                string tmp = paths.front();
                tmp.push_back('L');
                paths.push(tmp);
            }
            if (nodes.front()->right != NULL) {
                nodes.push(nodes.front()->right);
                string tmp = paths.front();
                tmp.push_back('R');
                paths.push(tmp);
            }
        }
        nodes.pop(); paths.pop();
    }
    return "";
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    // 1. Root to leaf path for both source and destination nodes.
    // 2. Leave the common prefix.
    // 3. Reverse the dest path and merge.
    cout << startValue << " " << destValue << endl;
    string srcPath = root2leafPath (root, startValue), destPath = root2leafPath (root, destValue);
    cout << srcPath << " " << destPath << endl;
    int prefix = 0;
    for (prefix = 0; prefix < min(srcPath.length(), destPath.length()); prefix++) {
        if (srcPath[prefix] == destPath[prefix])
            prefix++;
        else
            break;
    }
    string result = "";
    for (int i = srcPath.length() - 1; i >= prefix; i--)
        result.push_back('U');
    for (int i = prefix; i < destPath.length(); i++)
        result.push_back(destPath[i]);
    return result;
}

int main () {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    cout << getDirections (root, root->left->left->val, root->right->left->val) << endl;
    return 0;
}
