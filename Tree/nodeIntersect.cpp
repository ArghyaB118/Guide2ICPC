#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    unordered_set<ListNode*> node_pointer;
    cout << "here" << endl;
    while (headA != NULL) {
        node_pointer.insert(headA);
        headA = headA->next;
    }
    cout << "here" << endl;
    while (headB != NULL) {
        cout << headB->val << endl;
        if (node_pointer.find(headB) != node_pointer.end())
            return headB;
        headB = headB->next;
    }
    return NULL;
}

int main () {
	struct ListNode* headA = new ListNode(4);
	headA->next = new ListNode(1);
	headA->next->next = new ListNode(4);
    headA->next->next->next = new ListNode(3);

	struct ListNode* headB = new ListNode(4);
    headB->next = new ListNode(3);
    cout << getIntersectionNode(headA, headB)->val << endl;
	return 0;
}