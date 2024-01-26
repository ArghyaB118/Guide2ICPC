//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() {
		this->val = 0;
		this->next = NULL;
	}
	ListNode(int x) : val(x), next(NULL) {}
};


void insert(int new_val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->val = new_val;
    new_node->next = head;
    head = new_node;
}

void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr-> val << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}


struct ListNode* push(struct ListNode **head, int val) {
	struct ListNode *node = new ListNode(val);
	node->next = *head;
	return node;
}

void push2(struct ListNode **head, int val) {
	/* allocate node */
	struct ListNode *node = new ListNode();
	/* put in the data */
	node->val = val;
	/* link the old list off the new node */
	node->next = *head;
	/* move the head to point to the new node */
	*head = node;
}

void printList(ListNode *head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// How to delete a node from a list
void deleteNode(ListNode* node) {
    while (node->next != NULL) {
        node->val = node->next->val;
        if (node->next->next != NULL)
            node = node->next;
        else
            node->next = NULL;
    }
}

// Reverse a linked list
ListNode* reverseList (ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* listnode = head->next;
    ListNode* reverselistnode = head;
    reverselistnode->next = NULL;
    while (listnode != NULL) {
        ListNode* temp = listnode;
        listnode = listnode->next;
        temp->next = reverselistnode;
        reverselistnode = temp;
    }
    return reverselistnode;
}


bool hasCycle (ListNode *head) {
    unordered_set<ListNode*> s;
    while(head != NULL) {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
}
    
bool hasCycle2 (ListNode *head) {
    ListNode *slow_p = head, *fast_p = head;
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
            return true;
    }
    return false;
}

/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
    int num1, num2;
    while (l1 != NULL) {
        num1 *= 10; num1 += l1->val;
    }
    while (l2 != NULL) {
        num2 *= 10; num2 += l2->val;
    }
    num1 += num2;
    stack<int> st;
    while (num1 != 0) {
        st.push(num1 % 10); num1 /= 10;
    }
    while (!st.empty()) {
        cout << st.top() << endl; st.pop();
    }
    // ListNode* sum
    return NULL;
}

/*
You are given a singly-linked list that contains N integers. 
A subpart of the list is a contiguous set of even elements, 
bordered either by either end of the list or an odd element. 
For example, if the list is [1, 2, 8, 9, 12, 16], 
the subparts of the list are [2, 8] and [12, 16].

Then, for each subpart, the order of the elements is reversed. 
In the example, this would result in the new list, [1, 8, 2, 9, 16, 12].
The goal of this question is: given a resulting list, 
determine the original order of the elements.
*/

void appendNode (ListNode *head, int val) {
	while (head->next != NULL) 
		head = head->next;
	struct ListNode *node = new ListNode(val);
	head->next = node;
	node->next = NULL;
}

struct ListNode* reverse (ListNode* Node) {
	struct ListNode *head = new ListNode(Node->val);
	Node = Node->next;
	stack<int> st;
	while (Node != NULL) {
		if (Node->val % 2 != 0) {
			if (st.empty())
				appendNode(head, Node->val);
			else {
				while (!st.empty()) {
					appendNode(head, st.top());
					st.pop();
				}
				appendNode(head, Node->val); // printList(head);
			}
		}
		else
			st.push(Node->val);
		Node = Node->next;
	}
	while (!st.empty()) {
		appendNode(head, st.top());
		st.pop();
	}
	return head;
}

struct ListNode *arrayToList(int arr[], int size) {
	ListNode *root = NULL;
	for (int i = size - 1; i >= 0; i--) {
		push2(&root, arr[i]);
	}
	return root;
}


/*
How to count duplicates in a linked list
*/

int countDuplicate(ListNode* head) {
	int count = 0;
	while (head->next != NULL) {
		ListNode *ptr = head->next;
		while (ptr != NULL) {
			if (head->val == ptr->val) {
				count++;
			}	
			ptr = ptr->next;
		}
		head = head->next;
	}
	return count;
}

int countDuplicateHash(ListNode* head) {
	if (head == NULL)
		return 0;
	int count = 0;
	vector<int> elts;
	while (head != NULL) {
		vector<int>::iterator it = find(elts.begin(), elts.end(), head->val);
		if (it != elts.end())
			count++;
		elts.insert(elts.begin(), head->val);
		head = head->next;
	}
	return count;
}

/* LC#21
 
How to merge two sorted linked list
https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
You are given the heads 
of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. 
The list should be made 
by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]
*/

ListNode* mergeTwoSortedLists (ListNode* l1, ListNode* l2) {
	ListNode dummy(-1);
	ListNode* tail = &dummy;
	dummy.next = NULL;
	while(1) {
		if (l1 == NULL) {
			tail->next = l2;
			break;
		}
		else if (l2 == NULL) {
			tail->next = l1;
			break;
		}
		if (l1->val > l2->val) {
			tail->next = l2;
			l2 = l2->next;
		}
		else {
			tail->next = l1;
			l1 = l1->next;
		}
		tail = tail->next;
	}
	return dummy.next;
}

/* LC#23
 
You are given an array of k linked-lists lists, 
each linked-list is sorted in ascending order.

Merge all the linked-lists into 
one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
1->4->5,
1->3->4,
2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Input: lists = []
Output: []

Input: lists = [[]]
Output: []
*/


ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)
        return NULL;
    ListNode dummy(-1);
    ListNode* tail = &dummy;
    dummy.next = NULL;
    while (1) {
        int count = 0;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != NULL)
                count++;
        if (count == 0) {
            cout << "here" << endl;
            return dummy.next;
        }
        else if (count == 1) {
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    tail->next = lists[i];
                    return dummy.next;
                }
            }
        }
        else {
            // break;
            int tmp = 10000;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL)
                    tmp = min(tmp, lists[i]->val);
            }
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    if (lists[i]->val == tmp) {
                        tail->next = lists[i];
                        lists[i] = lists[i]->next;
                        tail = tail->next;
                    }
                }
            }
        }
    }
    return dummy.next;
}



// https://www.geeksforgeeks.org/reverse-a-linked-list/
ListNode* reverseList(ListNode* head) {
	ListNode* current = head; 
	ListNode *prev = NULL, *next = NULL;
	while (current != NULL) {
		next = current->next;// cout << next->val;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void swapNode(int x, int y) {
    if (x == y) return;
    // Search for x (keep track of prevX and CurrX)
    Node *prevX = NULL, *currX = head;
    while (currX && currX->val != x) {
        prevX = currX;
        currX = currX->next;
    }
    // Search for y (keep track of prevY and CurrY)
    Node *prevY = NULL, *currY = head;
    while (currY && currY->val != y) {
        prevY = currY;
        currY = currY->next;
    }
    if (currX == NULL || currY == NULL) return;
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        head = currY;
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        head = currX;
    // Swap next pointers
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

int main() {
	struct ListNode *head = new ListNode(1);
	head = push(&head, 2);
	head = push(&head, 3);
	push2(&head, 4);
	printList(head); deleteNode(head); printList(head);

	int arr[] = {1, 8, 2, 9, 16, 12};
	int size = sizeof(arr) / sizeof(arr[0]);
	struct ListNode *head2 = arrayToList(arr, size);
	printList(head2); head2 = reverse(head2); printList(head2);

	int arr2[] = {1, 2, 2, 3, 4, 4, 5, 6};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	struct ListNode *head3 = arrayToList(arr2, size2);
	cout << countDuplicate(head3) << endl;
	cout << countDuplicateHash(head3) << endl;
    
    ListNode* l1 = NULL; l1->val = 5; l1->next->val = 6; l1->next->next->val = 4;
    ListNode* l2 = NULL; l2->val = 2; l2->next->val = 4; l2->next->next->val = 3;
	return 0;
}
