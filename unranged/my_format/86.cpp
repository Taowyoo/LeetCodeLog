// my solution
// use two pointer, one for iterate the list, one of pos for inserting nodes with value smaller then x
// iterate the linked list, move the node with value smaller than x ahead
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode prehead(INT_MIN,head);
        ListNode* small_cur = &prehead;
        ListNode* cur = small_cur;
        while(cur && cur->next){
            if(cur->next->val < x){
                if(cur->next != small_cur->next){
                    ListNode* removed = removeAfter(cur);
                    insertAfter(small_cur, removed);
                    small_cur = removed;
                    continue;
                }
                else{
                    small_cur = cur->next;
                }
            }
            cur = cur->next;
        }
        return prehead.next;
    }
private:
    ListNode* removeAfter(ListNode* node){
        ListNode* removed = node->next;
        if(!removed) return removed;
        node->next = removed->next;
        return removed;
    }
    void insertAfter(ListNode* pos, ListNode* node){
        ListNode* tmp = pos->next;
        pos->next = node;
        node->next = tmp;
    }
};