/* LC#382
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

 

Constraints:
The number of nodes in the linked list will be in the range [1, 104].
-104 <= Node.val <= 104
At most 104 calls will be made to getRandom.
 

Follow up:
What if the linked list is extremely large and its length is unknown to you?
Could you solve this efficiently without using extra space?
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