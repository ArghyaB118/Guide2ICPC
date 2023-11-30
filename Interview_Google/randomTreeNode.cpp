/* Google Interview: Summer 2023: November 2022
 Question 1: Build a data structure of a given class.
 So that a random node can be returned in O(1).
 A node only points to its parent node.
 It's an n-ary tree.
 Question 2: Return a random leaf, do better than O(n).*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    TreeNode* parent;
    TreeNode () : parent(nullptr) {}
};

class Tree {
private:
    int capacity_;
    vector<TreeNode*> nodes, leaves;
    unordered_set<TreeNode*> leaveSet;
public:
    TreeNode* root_;
    // Creates Tree instance in which the number of nodes can not exceed capacity and the root node is created.
    // 1 <= # of nodes <= capacity
    Tree (int capacity) : root_(new TreeNode()), capacity_(capacity) {
        this->nodes.push_back(this->root_);
        this->leaves.push_back(this->root_);
        this->leaveSet.insert(this->root_);
    }
    // Creates a node that is attached to a parent node that is guaranteed to already exist in the Tree.
    TreeNode* createNode(TreeNode* parent) {
        if (this->nodes.size() == this->capacity_)
            return NULL;

        struct TreeNode* tmp = new TreeNode;
        tmp->parent = parent;
        this->nodes.push_back(tmp);

        this->leaves.push_back(tmp);
        this->leaveSet.insert(tmp);
        // if (find (leaves.begin(), leaves.end(), parent) != leaves.end())
        // leaves.erase(parent);
        if (leaveSet.find(parent) != leaveSet.end())
            leaveSet.erase(parent);

        return tmp;
    }
    
    // Returns a random node in the Tree. Each node in the Tree has an equal probability to be selected.
    TreeNode* getRandomNode() {
        int currSize = this->nodes.size();
        int rand = rand() % (currSize); // 0 -- currSize - 1
        return this->nodes[rand];
    }
    
    // Returns a random leaf in the Tree. Each leaf in the Tree has an equal probability to be selected.
    TreeNode* getRandomLeaf() {
        int currLeafSize = this->leaves.size();
        int rand = rand() % (currLeafSize); // 0 -- currLeafSize - 1
        return this->leaves[rand];
    }

};

int main () {
    int capacity = 100;
    Tree *obj = new Tree(capacity);
    struct TreeNode *node1 = obj->createNode(obj->root_);
    struct TreeNode *node2 = obj->createNode(obj->root_);
    struct TreeNode *node3 = obj->createNode(node1);
    struct TreeNode *node4 = obj->createNode(node1);
    struct TreeNode *node5 = obj->createNode(node2);
    obj->getRandomNode();
    obj->getRandomLeaf();
    return 0;
}
