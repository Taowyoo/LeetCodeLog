// my solution
// Time: O(n)
// Space: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int i = INT_MAX;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

// hashtable solution
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodesSeen;
        while (head) {
            if (nodesSeen.count(head)) {
                return true;
            } else {
                nodesSeen.emplace(head);
            }
            head = head->next;
        }
        return false;
    }
};