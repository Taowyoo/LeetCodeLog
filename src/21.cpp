// my solution
// Time: O(m+n)
// Space: O(m+n), if does not count result singly-linked list space O(1)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!(l1 || l2)) return nullptr;
        ListNode* cur = new ListNode();
        ListNode* res = cur;
        while(l1 || l2){
            
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            if( val1 < val2){
                if(l1){
                    cur->val = val1;
                    l1 = l1->next;
                }
                else{
                    cur->val = val2;
                    l2 = l2->next;
                }
            }
            else {
                if(l2){
                    cur->val = val2;
                    l2 = l2->next;
                }
                else{
                    cur->val = val1;
                    l1 = l1->next;
                }
            }
            if(!(l1 || l2)) break;
            cur->next = new ListNode();
            cur = cur->next;
        }
        
        return res;
    }
};
// my solution improved
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) const{
        if(!(l1 || l2)) return nullptr;
        ListNode prehead;
        ListNode** cur = &(prehead.next);  // use double pointer to track current position
        ListNode* n1 = l1; 
        ListNode* n2 = l2;
        while(n1 && n2){
            if(n1->val < n2->val){
                *cur = new ListNode(n1->val);
                cur = &((*cur)->next);
                n1 = n1->next;
            }
            else{
                *cur = new ListNode(n2->val);
                cur = &((*cur)->next);
                n2 = n2->next;
            }
        }
        n1 = n1 ? n1 : n2;  // add the rest of nodes behind
        while(n1){
            *cur = new ListNode(n1->val);
            cur = &((*cur)->next);
            n1 = n1->next;
        }
        return prehead.next;
    }
};


// Solutions without create new Linked List:

// A recursive solution
// Time: O(m+n)
// Space: O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
		if(l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
    }
};

// use dummy and no recursion
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};


