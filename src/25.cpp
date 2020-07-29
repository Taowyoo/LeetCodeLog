// my solution
// Time: O(n)
// Space: O(1)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2) return head;
        ListNode dummy(0,head);
        ListNode* cur = &dummy;
        while(cur = reverseNextKNode(cur,k));
        return dummy.next;
    }
private:
    ListNode* reverseNextKNode(ListNode* pre, int k){
        // check there are k nodes left
        ListNode* test = pre->next;
        for(int i = 0; i < k; ++i){
            if(!test) return nullptr;
            test = test->next;
        }
        // reverse next k nodes
        ListNode* first = pre->next;
        ListNode* cur = first;
        ListNode* last = pre;
        while(k--){
            ListNode* tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        // currently:
        // cur point to the k+1-th node after pre
        // last point to the k-th node after pre
        first->next = cur;  // the next node of first node should be the k+1-th node
        pre->next = last;   // the next node of pre node should be the k-th node
        // return next pre
        return first;
    }
};

// recursive solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr && count != k) { // find the k+1 node
            curr = curr->next;
            count++;
        }
        if (count == k) { // if k+1 node is found
            curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
            // head - head-pointer to direct part, 
            // curr - head-pointer to reversed part;
            while (count-- > 0) { // reverse current k-group: 
                ListNode* tmp = head->next; // tmp - next head in direct part
                head->next = curr; // preappending "direct" head to the reversed list 
                curr = head; // move head of reversed part to a new node
                head = tmp; // move "direct" head to the next node in direct part
            }
            head = curr;
        }
        return head;
    }
};