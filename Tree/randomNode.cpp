/* LC#382

Given a singly linked list, 
return a random node's value from the linked list. 
Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object 
with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list 
and returns its value. 
All the nodes of the list 
should be equally likely to be chosen.

 

Constraints:
The number of nodes in the linked list 
will be in the range [1, 10^4].
-10^4 <= Node.val <= 10^4
At most 10^4 calls will be made to getRandom.
 

Follow up:
What if the linked list is extremely large 
and its length is unknown to you?
Could you solve this efficiently 
without using extra space?
*/

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// extra space: O(n)
class randomNode {
	vector<int> nums;
public:
    randomNode (ListNode* head) {
        while (head) {
        	this->nums.push_back(head->val);
        	head = head->next;
        }
    }
    
    int getRandom() {
    	int n = this->nums.size();
    	return this->nums[rand() % n];
    }
};

/* Pros: no extra space
	can return the node itself, not the value
	repition of same values in multiple nodes allowed */
// Idea: Reservoir sampling
/* Pr[n^th element chosen] = 1 / n
	Pr[(n-1)^th element chosen] = 1 / (n - 1) - 1 / n = 1 / n */
// Well, it takes more time on LC :(
class randomNode2 {
	ListNode *head;
public:
    randomNode2 (ListNode* head) {
    	this->head = head;
    }
    
    int getRandom2() {
    	if (!head)
    		return -1;
    	if (!head->next)
    		return head->val;
    	ListNode *tmp = head;
    	int n = 2, random = tmp->val;
    	tmp = tmp->next;
    	while (tmp) {
    		// cout << tmp->val << " " << n << endl;
    		if (rand() % n == 0)
    			random = tmp->val;
    		tmp = tmp->next;
    		n++;
    	}
    	return random;
    }
};

/* LC#138

A linked list of length n is given 
such that each node contains an additional random pointer, 
which could point to any node in the list, or null.

Construct a deep copy of the list. 
The deep copy should consist of exactly n brand new nodes, 
where each new node has its value 
set to the value of its corresponding original node. 
Both the next and random pointer of the new nodes 
should point to new nodes in the copied list 
such that the pointers in the original list 
and copied list represent the same list state. 
None of the pointers in the new list 
should point to nodes in the original list.

For example, 
if there are two nodes X and Y in the original list, 
where X.random --> Y, 
then for the corresponding two nodes x and y 
in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented 
in the input/output as a list of n nodes. 
Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) 
that the random pointer points to, 
or null if it does not point to any node.
Your code will only be given the head of the original linked list.
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// beats 73% LC users
Node* copyRandomList(Node* head) {
	unordered_map<Node*, int> oldNodeIndex;
	vector<Node*> newNodes;
	if (head == NULL)
		return NULL;
	Node* head_copy = head;
	int i = 0;
	while (head_copy != NULL) {
		Node* newNode = new Node(head_copy->val);
		newNodes.push_back(newNode);
		oldNodeIndex[head_copy] = i;
		i++;
		head_copy = head_copy->next;
	}
	for (int i = 0; i < newNodes.size(); i++) {
		if (i == newNodes.size() - 1)
			newNodes[i]->next = NULL;
		else
			newNodes[i]->next = newNodes[i + 1];
		if (head->random != NULL)
			newNodes[i]->random = newNodes[oldNodeIndex[head->random]];
		head = head->next;
	}
	return newNodes[0];
}


int main () {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	// randomNode* obj = new randomNode(head);
	// cout << obj->getRandom() << " " << obj->getRandom() << " " << obj->getRandom() << endl;
	randomNode2* obj2 = new randomNode2(head);
	// cout << obj2->getRandom2() << endl;
	cout << obj2->getRandom2() << " " << obj2->getRandom2() << " " << obj2->getRandom2() << endl;
}