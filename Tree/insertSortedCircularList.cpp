/* LC#708

Given a Circular Linked List node, 
which is sorted in non-descending order, 
write a function to insert a value insertVal 
into the list such that it remains a sorted circular list. 
The given node can be a reference to any single node 
in the list and may not necessarily be 
the smallest value in the circular list.

If there are multiple suitable places for insertion, 
you may choose any place to insert the new value. 
After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), 
you should create a new single circular list 
and return the reference to that single node. 
Otherwise, you should return the originally given node.
*/
// beats 100% LC users
Node* insert(Node* head, int insertVal) {
	if (head == NULL) {
		Node* newhead = new Node(insertVal);
		newhead->next = newhead;
		return newhead;
	}
	if (head->next == head) {
		Node* node = new Node(insertVal, head);
		head->next = node;
		return head;
	}
	Node* node = head;
	while (node != NULL) {
		node = node->next;
		if ((node->val <= insertVal 
			&& node->next->val >= insertVal)
			|| (node->val <= insertVal 
				&& node->next->val < node->val 
				&& node->next->val < insertVal)
			|| (node->val < insertVal 
				&& node->next->val < node->val 
				&& node->next->val <= insertVal)
			|| (insertVal <= node->val 
				&& node->next->val < node->val 
				&& insertVal < node->next->val)
			|| (insertVal < node->val 
				&& node->next->val < node->val 
				&& insertVal <= node->next->val)) {
			Node* newnode = new Node(insertVal, node->next);
			node->next = newnode; break;
		}
		if (node == head) {
			Node* newnode = new Node(insertVal, node->next);
			node->next = newnode; break;
		}
	}
	return head;
}