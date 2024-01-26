/* LC#106

 Given two integer arrays inorder and postorder 
 where inorder is the inorder traversal of a binary tree 
 and postorder is the postorder traversal of the same tree, 
 construct and return the binary tree.
 
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

TreeNode* buildTreeUtil (int start, int end, 
        vector<int>& inorder,
        vector<int>& postorder, 
        unordered_map<int, int>& inorder_index, 
        unordered_map<int, int>& postorder_index) {
    cout << start << " " << end << endl;
    if (start > end)
        return NULL;
    else if (start == end) {
        TreeNode* node = new TreeNode(postorder[start]);
        return node;
    }
    else if (start == end - 1) {
        TreeNode* node = new TreeNode(postorder[end]);
        if (postorder[end] == inorder[end])
            node->left = new TreeNode(postorder[start]);
        else if (postorder[end] == inorder[start])
            node->right = new TreeNode(postorder[start]);
        return node;
    }
    int inIndex = inorder_index[postorder[end]]; 
    // cout << inIndex << endl;
    TreeNode* node = new TreeNode(postorder[end]);


    node->left = buildTreeUtil 
        (start, 
            postorder_index[inorder[inIndex + 1]] - 1, 
            inorder, postorder, 
            inorder_index, postorder_index);
    node->right = buildTreeUtil 
        (postorder_index[inorder[inIndex + 1]], 
            end - 1, 
            inorder, postorder, 
            inorder_index, postorder_index);
    return node;
}

TreeNode* buildTree (vector<int>& inorder, 
    vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> inorder_index;
    unordered_map<int, int> postorder_index;
    for (int i = 0; i < n; i++) {
        inorder_index[inorder[i]] = i;
        postorder_index[postorder[i]] = i;
    }
    return buildTreeUtil 
        (0, n - 1, 
            inorder, postorder, 
            inorder_index, postorder_index);
}

/* LC#105

Given two integer arrays preorder and inorder 
where preorder is the preorder traversal 
of a binary tree and inorder is the inorder traversal 
of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/


void bfs (TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tmp = q.front();
        cout << tmp->val << " ";
        if (tmp->left) { q.push(tmp->left); }
        if (tmp->right) { q.push(tmp->right); }
        q.pop();
    }
    cout << endl;
}

int main () {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = buildTree(inorder, postorder);
    cout << "here" << endl;
    bfs(root);
    return 0;
}
