// my solution
// 1. lind the end with the head of the linked list
// 2. break the cycle linked list at right pos according to k and length of linked list
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
    ListNode* rotateRight(ListNode* head, int k) {
        // corner case
        if(k == 0 || !head) return head;
        // get end ListNode and ListNode number len
        ListNode* end = head;
        int len = 1;
        while(end->next){
            end = end->next;
            ++len;
        }
        if(len == 1 || k % len == 0) return head; // corner case
        // connect end's next to head
        end->next = head;
        // disconnect the cycle after (len - k % len)th node
        int p = len - k % len;
        end = head;
        ListNode* ans;
        for(int i = 1; i < p; ++i){
            end = end->next;
        }
        ans = end->next;
        end->next = nullptr;
        return ans;
    }
    
};