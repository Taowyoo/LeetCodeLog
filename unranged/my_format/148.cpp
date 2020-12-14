// my not accapted solution
// quick sort
// Time: O(nlog(n))
// Space: O(log(n))~O(n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* tail = head;
        ListNode* h = head;
        while(tail->next) tail =  tail->next;
        listQS(h,tail);
        return head;
    }
    void listQS(ListNode* left, ListNode* right){
        if(less(left , right)){
            ListNode* i = adjust(left,right);
            listQS(left,i);
            listQS(i->next,right);
        }
    }
    ListNode* adjust(ListNode* left, ListNode* right){
        ListNode* valNode = left;
        ListNode* cur = left;
        while(less(cur , right)){
            if(cur->next->val < valNode->val){
                if(cur->next == right) right = cur;
                ListNode* tmp = removeAfter(cur);
                if(valNode == right) right = tmp;
                insertBefore(valNode,tmp);
                valNode = tmp;
            }
            else{
                cur = cur->next;
            }
        }
        return valNode;
    }
    void insertBefore(ListNode* pos, ListNode* in){
        ListNode* tmp = pos->next;
        pos->next = in;
        in->next = tmp;
        swap(pos->val,in->val);
    }
    ListNode* removeAfter(ListNode* pos){
        ListNode* removed = pos->next;
        pos->next = removed->next;
        removed->next = nullptr;
        return removed;
    }
    bool less(ListNode* left, ListNode* r){
        ListNode* l = left;
        if(!l) return false;
        while(l->next){
            if(l->next == r) return true;
            l = l->next;
        }
        return false;
    }
    
};

// merge sort
// O(nlogn) time, O(1) space. 
ListNode* sortList(ListNode* head){
    bool done = (!head);
    // Keep partitioning our list into bigger sublists length. Starting with a size of 1 and doubling each time
    for (int step = 1; !done; step *= 2) {
      done = true;
      ListNode** next_ptr = &head;
      ListNode* remaining = head;
      ListNode* list[2];
      do {
        // Split off two sublists of size step
        for (auto& sub_head : list) {
          sub_head = remaining;
          ListNode* tail = nullptr;
          for (int i = 0; i < step && remaining; ++i, remaining = remaining->next) {
            tail = remaining;
          }
          // Terminate our sublist
          if (tail) {
            tail->next = nullptr;
          }
        }

        // We're done if these are the first two sublists in this pass and they
        // encompass the entire primary list
        done &= !remaining;

        // If we have two sublists, merge them into one
        if (list[1]) {
          while (list[0] || list[1]) {
            int idx = (!list[1] || list[0] && list[0]->val <= list[1]->val) ? 0 : 1;
            *next_ptr = list[idx];
            list[idx] = list[idx]->next;
            next_ptr = &(**next_ptr).next;
          }

          // Terminate our new sublist
          *next_ptr = nullptr;
        } else {
          // Only a single sublist, no need to merge, just attach to the end
          *next_ptr = list[0];
        }
      } while (remaining);
    }
    return head;
  }

// a better look bottom to up merge sort
/**
 * Merge sort use bottom-up policy, 
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
*/
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if(!head || !(head->next)) return head;
		
		//get the linked list's length
		ListNode* cur = head;
		int length = 0;
		while(cur){
			length++;
			cur = cur->next;
		}
		
		ListNode dummy(0);
		dummy.next = head;
		ListNode *left, *right, *tail;
		for(int step = 1; step < length; step <<= 1){
			cur = dummy.next;
			tail = &dummy;
			while(cur){
				left = cur;
				right = split(left, step);
				cur = split(right,step);
				tail = merge(left, right, tail);
			}
		}
		return dummy.next;
	}
private:
	/**
	 * Divide the linked list into two lists,
     * while the first list contains first n ndoes
	 * return the second list's head
	 */
	ListNode* split(ListNode *head, int n){
		//if(!head) return NULL;
		for(int i = 1; head && i < n; i++) head = head->next;
		
		if(!head) return NULL;
		ListNode *second = head->next;
		head->next = NULL;
		return second;
	}
	/**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */
	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
		ListNode *cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while(cur->next) cur = cur->next;
		return cur;
	}
};

// a great quick sort with only one function
ListNode* sortList(ListNode* head, ListNode* tail = nullptr)
{
    if (head != tail) {
        // Use head node as the pivot node
        // Everything in the _smaller_ list will be less than _head_
        // and everything appearing after _head_ in the list is greater or equal
        ListNode* smaller;
        ListNode** smaller_next = &smaller;
        for (ListNode** prev = &head->next; *prev != tail; ) {
        if (head->val > (**prev).val) {
            *smaller_next = *prev;
            smaller_next = &((**smaller_next).next);

            // Remove smaller node from original list
            *prev = (**prev).next;
        } else {
            // Correct position, skip over
            prev = &((**prev).next);
        }
        }

        // Connect the end of smaller list to the head (which is the partition node)
        // We now have. [smaller list...] -> head -> [larger list]
        *smaller_next = head;

        // Continue to sort everything after head
        head->next = sortList(head->next, tail);

        // Sort everything upto head
        head = sortList(smaller, head);
    }
    return head;
}

// Other's Quick Sort
// two function version
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* tail = head;
        while(tail->next) tail = tail->next;
        quickSort(head, tail);
        return head;
    }
    
    void quickSort(ListNode* head, ListNode* tail){
        if(!head || head == tail) return;
        ListNode* pivot = partition(head, tail);
        quickSort(head, pivot);
        quickSort(pivot->next, tail);
    }
    
    ListNode* partition(ListNode* head, ListNode* tail){
        int pivot = head->val;
        ListNode* pivotNode = head;
        ListNode* walker = head->next;
        ListNode* runner = head->next;
        while(runner && runner != tail->next){
            if(runner->val < pivot){
                swap(walker, runner);
                walker = walker->next;
                pivotNode = pivotNode->next;
            }
            runner = runner->next;
        }
        swap(head->val, pivotNode->val);
        return pivotNode;
    }
  
};