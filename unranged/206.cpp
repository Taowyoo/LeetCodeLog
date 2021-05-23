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
// official solution
// continuously put the current-next to head
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* currentHead = head;
        while (head->next) {
            ListNode* p = head->next;
            head->next = p->next;
            p->next = currentHead;
            currentHead = p;
        }
        return currentHead;
    }
};
//================================================================================
// my solution
// from beginning to end, reverse the pointer direction
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* last = nullptr;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        return last;
    }
};