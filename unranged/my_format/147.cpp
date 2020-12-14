// my solution
// sort the linked list by inserting to a new sorted linked list
// Time: O(n^2)
// Space: O(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prehead = new ListNode(INT_MIN);
        ListNode* cur = head;
        while(cur){
            insert(prehead,cur->val);
            cur = cur->next;
        }
        return prehead->next;
    }
private:
    void insert(ListNode* begin, int val){
        ListNode* cur = begin->next;
        ListNode* pos = begin;
        while(cur && val > cur->val){
            cur = cur->next;
            pos = pos->next;
        }
        ListNode* tmp = pos->next;
        pos->next = new ListNode(val,tmp);
    }
};
// Better one
// Keep a sorted partial list (head) and start from the second node (head -> next), 
// each time when we see a node with val smaller than its previous node, 
// we scan from the head and find the position that the node should be inserted. 
// Since a node may be inserted before head, we create a dummy head that points to head.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if ((cur -> next) && (cur -> next -> val < cur -> val)) {
                while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
                    pre = pre -> next;
                }
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                pre = dummy;
            }
            else {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};
// better solution from java example
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( head == nullptr ){
			return head;
		}
		
		ListNode* helper = new ListNode(); //new starter of the sorted list
		ListNode* cur = head; //the node will be inserted
		ListNode* pre = helper; //insert node between pre and pre.next
		ListNode* next = nullptr; //the next node will be inserted
		//not the end of input list
		while( cur != nullptr ){
			next = cur->next;
			//find the right place to insert
			while( pre->next && pre->next->val < cur->val ){
				pre = pre->next;
			}
			//insert cur between pre and pre.next
			cur->next = pre->next;
			pre->next = cur;
			pre = helper;  // reset pre to point to beginning
			cur = next;  // process next node in original list
		}
		
		return helper->next;
    }

};