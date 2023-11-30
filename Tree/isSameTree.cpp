/* LC#100
 
 Given the roots of two binary trees p and q, write a function to check if they are the same or not.

 Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right; // Alternatively, struct Node* left, *right;
    TreeNode (int data) {
        this->val = data;
        left = right = NULL;
    }
};


bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL && q != NULL)
        return false;
    else if (q == NULL && p != NULL)
        return false;
    else {
        if (p->val == q->val)
            return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));                 else
                return false;
    }
}

int main () {
    TreeNode *root1 = new TreeNode(5);
    TreeNode *root2 = new TreeNode(5);
    cout << boolalpha << isSameTree (root1, root2) << endl;
    return 0;
}

