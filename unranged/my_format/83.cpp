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
    ListNode* deleteDuplicates(ListNode* head) {
        auto* cur = head;
        while(cur){
            // find next different value node
            auto val = cur->val;
            auto* tmp = cur;
            while(tmp && tmp->val == val) tmp = tmp->next;
            cur->next = tmp;
            cur = tmp;
        }
        return head;
    }
};

// single loop implementation
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* cur = head;
        while(cur->next) {
        	if (cur->val == cur->next->val) {
        		cur->next = cur->next->next;
        	}
        	else cur = cur->next;
        }
        return head;
    }
};