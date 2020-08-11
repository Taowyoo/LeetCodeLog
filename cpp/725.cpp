// my solution
// 1. count the length of linked list
// 2. by computing the length and k, put corrent number of top nodes into vector
// Time: O(n), let n is the length of linked list
// Space: O(n), if not count answer vector, it will be O(1)
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // corner case
        if(!root) return vector<ListNode*>(k, nullptr);
        if(k == 1) return vector<ListNode*>{root};
        vector<ListNode*> res(k, nullptr);
        // count the length of Link List
        int len = 0;
        ListNode* cur = root;
        while(cur){
            cur = cur->next;
            ++len;
        }
        // compute length for each part
        int step = len / k;
        int extra = len - step * k;
        for(int i = 0; i < k; ++i){
            int n = step + (extra-- > 0 ? 1 : 0);
            res[i] = splitAfterNth(root, n); // get top n nodes
        }
        return res;
    }
private:
    ListNode* splitAfterNth(ListNode*& head, int N){
        ListNode* old_head = head;
        ListNode* cur = head;
        int i = 1;
        while(cur && i < N){
            cur = cur->next;
            i++;
        }
        if(cur){
            head = cur->next;
            cur->next = nullptr;
        }
        else{
            head = cur;
        }
        return old_head;
    }
};