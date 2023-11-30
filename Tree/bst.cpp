// https://hub.packtpub.com/binary-search-tree-tutorial/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
	Node (int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};


// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
// max(left subtree) < node < min(right subtree) V all nodes
bool isBST (struct Node* root, struct Node* l, struct Node* r) {
	if (root == NULL)
		return true;
	if (l != NULL && root->data <= l->data)
		return false;
	if (r != NULL && root->data >= r->data)
		return false;
	return isBST (root->left,l,root) && isBST (root->right, root, r);
}


/*
Balancing a Binary Tree to Binary Search Tree (BST)

Idea: Inorder traversal + building tree level order
InOrder: left, root, right
*/

void inOrder (struct Node *root, vector<int>& v) {
	if (root == NULL)
		return;
	inOrder(root->left, v);
	v.push_back(root->data);
	inOrder(root->right, v);
}

/*Node* buildTree (vector<int>& v, int left, int right) {
	if (left > right)
		return NULL;
	int mid = left + (right - left) / 2;
	Node *node = new Node(v[mid]);
	node->left = buildTree(v, left, mid - 1);
	node->right = buildTree(v, mid + 1, right);
	return node;
}*/

void buildTree (struct Node *root, vector<int>& v, int *pos) {
	if (root == NULL)
		return;
	buildTree (root->left, v, &pos);
	//root->data = v[*pos]; ++(*pos);
	cout << *pos << endl;
	buildTree (root->right, v, &pos);
}


void printLevelOrder (struct Node *root) {
	if (root == NULL)
		return;
	queue<Node*> q; q.push(root);
	while (!q.empty()) {
		Node* node = q.front(); q.pop();
		if (node->left != NULL)
			q.push(node->left); 
		if (node->right != NULL) 
			q.push(node->right);
		cout << node->data << " ";
	}
	cout << ": Level order traversal" << endl;
}

typedef pair<Node*, int> levelNode;
vector<vector<int>> LevelOrder (struct Node *root) {
    vector<vector<int>> result;
    if (root == NULL)
        return {{}};
    queue<levelNode> q; q.push(root);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        cout << node->data << " ";
    }
    cout << ": Level order traversal" << endl;
}

/*
Insert level Order traversal:
level order traversal of BST using queue until we find a node 
with either of the child empty, we insert there.
*/
void insertLevelOrder(struct Node* root, int val) {
	if (root == NULL)
		struct Node *root = new Node(val);
	queue<struct Node*> q;
	q.push(root); 
	while (!q.empty()) {
		struct Node *temp = q.front();
		q.pop();
		if (!temp->left) {
			temp->left = new Node(val);
			break;
		}
		else if (!temp->right) {
			temp->right = new Node(val);
			break;
		}
		else {
			q.push(temp->left);
			q.push(temp->right);
		}
	}
}



//deletion in BST, replacement by the deepest and rightmost node
struct node* deleteLevelOrder(struct node* root, int val) {
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL) {
		if (root->data == val)
			return NULL;
		else
			return root;
	}
	//now we start level order traversal and check 
	//where the node value is equal to the given 'val'
	//int temp_key = deleteDeepestNode(root); cout << temp_key << " ";
	queue<struct node*> q;
	q.push(root);
	struct node *replace_node, *deepest_node, *temp;
	while(!q.empty()) {
		deepest_node = q.front();
		q.pop();
		if (deepest_node->data == val)
			replace_node = deepest_node;
		if (deepest_node->left)
			q.push(deepest_node->left);
		if (deepest_node->right)
			q.push(deepest_node->right);
	}
	//now we replace the value
	if (replace_node)
		replace_node->data = deepest_node->data;
	
	//now deleting the deepest node
	q.push(root);
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == deepest_node) {
			temp = NULL;
			delete(deepest_node);
			break;
		}
		if (temp->left) {
			if (temp->left == deepest_node) {
				temp->left = NULL;
				delete(deepest_node);
				break;
			}
			else
				q.push(temp->left);
		}
		if (temp->right) {
			if (temp->right == deepest_node) {
				temp->right = NULL;
				delete(deepest_node);
				break;
			}
			else
				q.push(temp->right);
		}
	}
	return root;
}



int main() {
	struct Node *root = new Node(30);
	root->left = new Node(20);
	root->right = new Node(50);
	root->left->left = new Node(10);
	root->left->right = new Node(55);
	cout << boolalpha << isBST(root, NULL, NULL) << endl;


	vector<int> v; inOrder(root, v);
	for (auto & u : v)
		cout << u << " ";
	cout << ": Inorder traversal" << endl;
	sort(v.begin(), v.end());
	//struct Node* head = buildTree(v, 0, v.size());
	//struct Node* head = NULL;
	int pos = 0;
	buildTree(root, v, &pos);
	printLevelOrder(root);
	cout << boolalpha << isBST(root, NULL, NULL) << endl;

//	insertLevelOrder(head, 40);
//	cout << boolalpha << isBST(head, NULL, NULL) << endl;
	return 0;
}
