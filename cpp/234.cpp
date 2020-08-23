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
// Reverse Second Half In-place
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while(cur){
            ++len;
            cur = cur->next;
        }
        if(len == 1) return true;
        int hlen = len >> 1;
        ListNode* right = head;
        ListNode* left = reverseList(right, hlen);
        if(len % 2) right = right->next;
        while(left && right){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        
        return left == right;
    }
private:
    ListNode* reverseList(ListNode*& head,int n) {
        ListNode* cur = head;
        ListNode* last = nullptr;
        int i = 0;
        while(cur && i++ < n){
            ListNode* tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        head = cur;
        return last;
    }
};
//===================================================================================
// Recursive
// Time: O(n)
// Space: O(n)
class Solution {
    ListNode* frontPointer;
    bool recursivelyCheck(ListNode* currentNode){
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) return false;
            if (currentNode->val != frontPointer->val) return false;
            frontPointer = frontPointer->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};