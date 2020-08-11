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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // corner case
        if(n <= 0) return head;
        // create a prehead
        ListNode prehead(0,head);
        // find the n+1-th node
        ListNode* pre = findNthFromEnd(&prehead,n+1);
        // delete the n-th node behind the n+1-th node
        ListNode* tmp = pre->next->next;
        delete pre->next;
        pre->next = tmp;
        // return head;
        return prehead.next;
    }
private:
    /*
        return the n-th node from end of list
        @param head the head of the linked list
        @param n the number of node from end of list
        @return the n-th node from end of list
    */
    ListNode* findNthFromEnd(ListNode* head, int n) const{
        ListNode* res = head;
        ListNode* cur = head;
        int len = 0;
        while(cur){
            cur = cur->next;
            ++len;
            if(len > n) res = res->next;
        }
        return res;
    }
};

// better and clear approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }

};