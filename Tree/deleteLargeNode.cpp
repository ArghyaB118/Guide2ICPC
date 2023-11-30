/* LC#2487
 
 You are given the head of a linked list.
 
 Remove every node which has a node with a strictly greater value anywhere to the right side of it.

 Return the head of the modified linked list.*/

#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare {
public:
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

void printList (ListNode* head) {
    while (head != NULL) {
        cout << head->val << endl;
        head = head->next;
    }
}

ListNode* removeNodes(ListNode* head) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    while (head != NULL) {
        pq.push(head);
        while (pq.top()->val < head->val) {
            pq.pop();
        }
        head = head->next;
    }
    ListNode* node = NULL;
    while (!pq.empty()) {
        ListNode* tmp = pq.top();
        tmp->next = node;
        node = tmp;
        // cout << pq.top()->val << endl;
        pq.pop();
    }
    printList (node);
    return node;
}

int main () {
    struct ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);
    // printList (head);
    removeNodes (head);
    return 0;
}
