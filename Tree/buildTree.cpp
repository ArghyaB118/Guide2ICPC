/* LC#106

 Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 
 Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 Output: [3,9,20,null,null,15,7]
 
 Constraints:
 1 <= inorder.length <= 3000
 postorder.length == inorder.length
 -3000 <= inorder[i], postorder[i] <= 3000
 inorder and postorder consist of unique values.
 Each value of postorder also appears in inorder.
 inorder is guaranteed to be the inorder traversal of the tree.
 postorder is guaranteed to be the postorder traversal of the tree.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeUtil (int start, int end, vector<int>& postorder, int pIndex, unordered_map<int, int> index) {
    if (start > end)
        return NULL;
    int inIndex = index[postorder[pIndex]];
    TreeNode* node = new TreeNode(postorder[pIndex]);
    node->left = buildTreeUtil (0, index - 1, postorder, pIndex, index);
    node->right = buildTreeUtil (index + 1, end, postorder, pIndex, index);
    return node;
}

TreeNode* buildTree (vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++)
        index[inorder[i]] = i;
    int pIndex = n - 1;
    return buildTreeUtil (0, n - 1, postorder, pIndex, index);
}
