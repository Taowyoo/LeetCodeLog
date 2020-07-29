// my solution
// Time: O(n)
// Space: O(1)
// maintain two pointer: last and cur, last is last unique value node, cur is the next unchecked node
// when traverse the linked list, continously find next different value node and update last and cur according to whether there are duplicates 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* cur = head;
        ListNode* last = &dummy;
        while(cur){
            ListNode* tmp = cur;
            auto val = cur->val;
            while(tmp && tmp->val == val) tmp = tmp->next;
            if(cur->next == tmp){
                cur = cur->next;
                last = last->next;
            }
            else{
                cur = tmp;
                last->next = tmp;
            }
        }
        return dummy.next;
    }
};

// a more clear approach
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode fakehead(0,head);
        ListNode* pre = &fakehead;
        ListNode* cur = head;
        while(cur){
            while(cur->next && cur->val == cur->next->val){
                cur = cur->next;
            }
            if(pre->next == cur){
                pre = pre->next;
            }
            else{
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return fakehead.next;
    }
};

// recursive approach
// if current node is not unique, return deleteDuplicates with head.next.
// If current node is unique, link it to the result of next list made by recursive call. Any improvement?
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        if (head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};