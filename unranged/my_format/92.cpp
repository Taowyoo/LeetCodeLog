// my solution
// 1. find the begin node for reversing
// 2. reverse next n - m + 1 node
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // find the (m - 1)th node
        ListNode prehead(0,head);
        ListNode* begin = &prehead;
        for(int i = 0; i < m - 1; ++i){
            begin = begin->next;
        }
        // reverse next n - m + 1 node
        ListNode* cur = begin->next;
        ListNode* new_end = cur;
        ListNode* last = begin;
        for(int i = 0; i < n - m + 1; ++i){
            ListNode* tmp = cur->next;
            cur->next = last;
            last = cur;  // at last the "last" will be the head of reversed part list
            cur = tmp;   // "cur" will be the node after "last" in original list
        }
        begin->next = last;
        new_end->next = cur;
        
        return prehead.next;
    }
    
};