// my solution
// Time: O(n)
// Memory: O(n)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // put data of linkedlist into vector
        vector<int> n1 ;
        vector<int> n2 ;
        ListNode* cur = l1;
        while(cur){
            n1.emplace_back(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur){
            n2.emplace_back(cur->val);
            cur = cur->next;
        }
        // add
        ListNode* last = nullptr;
        int c = 0;
        int i = n1.size() - 1;
        int j = n2.size() - 1;
        while(i >= 0 || j >= 0 || c > 0){
            c += i >= 0 ? n1[i--] : 0;
            c += j >= 0 ? n2[j--] : 0;
            // make addition and create result linked list by using last linknode
            ListNode* tmp = new ListNode(c % 10, last);
            c /= 10;
            last = tmp;
        }
        return last;
    }
};

// O(1) Solution
// use result Linked List to store l1 and l2, then add them together to get the result
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        while( curr1 ){ curr1=curr1->next; n1++; }
        while( curr2 ){ curr2=curr2->next; n2++; } 
        curr1 = l1; curr2 = l2;
        while( n1 > 0 && n2 > 0){
            int sum = 0;
            if( n1 >= n2 ){ sum += curr1->val; curr1=curr1->next; n1--;}
            if( n2 > n1 ){ sum += curr2->val; curr2=curr2->next; n2--;}
            res = addToFront( sum, res );
        }
        curr1 = res; res = NULL;
        while( curr1 ){
            curr1->val += carry; carry = curr1->val/10;
            res = addToFront( curr1->val%10, res );
            curr2 = curr1; 
            curr1 = curr1->next;
            delete curr2;
        }
        if( carry ) res = addToFront( 1, res );
        return res;
    }
    ListNode* addToFront( int val, ListNode* head ){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }