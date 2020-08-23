// Time: O(n)
Node* flatten(Node* head) {
    // loop over topest linked list
	for (Node* h = head; h; h = h->next)
	{
        // if has child, get in
		if (h->child)
		{
            // save original next node
			Node* next = h->next;
            // connect child behind current node
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
            // connect tail of child list to original current nest node
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
        // next loop begin at child just connected if has
	}
	return head;
}