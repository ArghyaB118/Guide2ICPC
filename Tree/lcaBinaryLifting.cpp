#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	vector<TreeNode*> descendants;
	vector<TreeNode*> ancestors;
};

TreeNode* node_create (int val, TreeNode* parent) {
	struct TreeNode *tmp = new TreeNode();
	tmp->val = val;
	if (parent != NULL) {
		parent->descendants.push_back(tmp);
		tmp->ancestors.push_back(parent);
	}
	return tmp;
}

void bfs (TreeNode* root) {
	if (root == NULL)
		return;
	std::queue<TreeNode*> q;
	q.push(root);
	cout << "BFS: ";
	while (!q.empty()) {
		cout << q.front()->val << " ";
		for (auto &i : q.front()->descendants) {
			q.push(i);
		}
		q.pop();
	}
	cout << endl;
}

int get_depth (TreeNode* node) {
	if (node == NULL)
		return -1;
	int depth = 0;
	while (node->ancestors.size() != 0) {
		// using the first one so that it is scalable to binary lifting
		node = node->ancestors[0];
		depth++;
	}
	return depth;
}

TreeNode* lca_linear (TreeNode* node1, TreeNode* node2) {
	int depth1 = get_depth(node1);
	int depth2 = get_depth(node2);
	cout << depth1 << " " << depth2 << endl;
	if (depth1 > depth2) {
		int tmp = depth1 - depth2;
		while (tmp > 0) {
			node1 = node1->ancestors[0];
			tmp--;
		}
	}
	else if (depth1 < depth2) {
		int tmp = depth2 - depth1;
		while (tmp > 0) {
			node2 = node2->ancestors[0];
			tmp--;
		}
	}
	cout << node1->val << " " << node2->val << endl;
	if (node1 == node2)
		return node1;
	while (node1 != node2) {
		node1 = node1->ancestors[0];
		node2 = node2->ancestors[0];
	}
	cout << node1->val << " " << node2->val << endl;
	return node1;
}

// https://cp-algorithms.com/graph/lca_binary_lifting.html
TreeNode* node_create_binary_lifting (int val, TreeNode* parent) {
	struct TreeNode *node = new TreeNode();
	node->val = val;
	if (parent != NULL) {
		parent->descendants.push_back(node);
		node->ancestors.push_back(parent);
		struct TreeNode *tmp = parent;
		int jump_size = 1, tmp_num = jump_size;
		while (tmp->ancestors.size() != 0 && tmp_num > 0) {
			tmp = tmp->ancestors[0];
			tmp_num--;
			if (tmp_num == 0) {
				node->ancestors.push_back(tmp);
				jump_size *= 2;
				tmp_num = jump_size;
			}
		}
	}
	return node;
}

void bfs_with_ancestors (TreeNode* root) {
	if (root == NULL)
		return;
	std::queue<TreeNode*> q;
	q.push(root);
	cout << "BFS: ";
	while (!q.empty()) {
		cout << q.front()->val << ": ";
		for (auto &i :q.front()->ancestors) {
			cout << i->val << " ";
		}
		cout << endl;
		for (auto &i : q.front()->descendants) {
			q.push(i);
		}
		q.pop();
	}
	cout << endl;
}

int get_depth_binary_lifting (TreeNode* node) {
	if (node == NULL)
		return -1;
	else if (node->ancestors.size() == 0)
		return 0;
	int depth = 1;
	while (node->ancestors.size() != 0) {
		// using the first one so that it is scalable to binary lifting
		int n = node->ancestors.size();
		node = node->ancestors[n - 1];
		while (n > 1) {
			depth *= 2;
		}
	}
	return depth;
}

TreeNode* go_up_the_tree (TreeNode* node, int level) {
	// cout << node->val << " " << level << endl;
	if (node == NULL)
		return NULL;
	if (level == 0)
		return node;
	if (level == 1)
		return node->ancestors[0];
	int i = 0, j = 1;
	while (j < level) {
		i++;
		j *= 2;
	}
	// cout << i << " " << j << endl;
	node = node->ancestors[i];
	return go_up_the_tree(node, level - j);
}

// two input nodes have the same depth.
// ancestor[0] (parent) check is performed here.
// a recursive function.
TreeNode* find_lcs_util (TreeNode* node1, TreeNode* node2) {
	cout << node1->val << " " << node2->val << endl;
	if (node1 == node2)
		return node1;
	if (node1->ancestors[0] == node2->ancestors[0])
		return node1->ancestors[0];
	int size = node1->ancestors.size();
	int tmp_num = 0;
	for (int i = 0; i < size; i++) {
		if (node1->ancestors[i] == node2->ancestors[i])
			tmp_num = i - 1;
	}
	if (tmp_num == 0)
		tmp_num = size - 1;
	return find_lcs_util(node1->ancestors[tmp_num], node2->ancestors[tmp_num]);
}

TreeNode* lca_binary_lifting (TreeNode* node1, TreeNode* node2) {
	int depth1 = get_depth(node1);
	int depth2 = get_depth(node2);
	cout << "Native depths: " 
		<< depth1 << " " << depth2 << endl;
	if (depth1 > depth2) {
		int tmp = depth1 - depth2;
		node1 = go_up_the_tree (node1, tmp);
	}
	else if (depth1 < depth2) {
		int tmp = depth2 - depth1;
		node2 = go_up_the_tree (node2, tmp);
	}
	cout << "After adjusting depths: " 
		<< node1->val << " " << node2->val << endl;
	if (node1 == node2)
		return node1;
	/*while (node1 != node2) {
		node1 = node1->ancestors[0];
		node2 = node2->ancestors[0];
	}
	cout << node1->val << " " << node2->val << endl;
	return node1;*/
	return find_lcs_util (node1, node2);
}

int main () {
	/*struct TreeNode *one = node_create(1, NULL);
	struct TreeNode *two = node_create(2, one);
	struct TreeNode *three = node_create(3, one);
	struct TreeNode *four = node_create(4, one);

	struct TreeNode *five = node_create(5, four);
	struct TreeNode *six = node_create(6, five);
	struct TreeNode *seven = node_create(7, five);
	struct TreeNode *eight = node_create(8, six);
	struct TreeNode *nine = node_create(9, six);
	struct TreeNode *ten = node_create(10, six);
	
	struct TreeNode *eleven = node_create(11, nine);
	struct TreeNode *twelve = node_create(12, nine);
	struct TreeNode *thirteen = node_create(13, eleven);
	struct TreeNode *fourteen = node_create(14, twelve);
	struct TreeNode *fifteen = node_create(15, twelve);
	struct TreeNode *sixteen = node_create(16, two);
	
	bfs(one);
	lca_linear(fourteen, sixteen);*/

	struct TreeNode *one = node_create_binary_lifting(1, NULL);
	struct TreeNode *two = node_create_binary_lifting(2, one);
	struct TreeNode *three = node_create_binary_lifting(3, one);
	struct TreeNode *four = node_create_binary_lifting(4, one);

	struct TreeNode *five = node_create_binary_lifting(5, four);
	struct TreeNode *six = node_create_binary_lifting(6, five);
	struct TreeNode *seven = node_create_binary_lifting(7, five);
	struct TreeNode *eight = node_create_binary_lifting(8, six);
	struct TreeNode *nine = node_create_binary_lifting(9, six);
	struct TreeNode *ten = node_create_binary_lifting(10, six);
	
	struct TreeNode *eleven = node_create_binary_lifting(11, nine);
	struct TreeNode *twelve = node_create_binary_lifting(12, nine);
	struct TreeNode *thirteen = node_create_binary_lifting(13, eleven);
	struct TreeNode *fourteen = node_create_binary_lifting(14, twelve);
	struct TreeNode *fifteen = node_create_binary_lifting(15, twelve);
	struct TreeNode *sixteen = node_create_binary_lifting(16, two);
	
	bfs_with_ancestors(one);
	cout << lca_binary_lifting(fourteen, sixteen)->val << endl;
	return 0;
}