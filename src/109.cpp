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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Approach 1: Recursion
/*
Intuition

The important condition that we have to adhere to in this problem is that we have to create a height balanced binary search tree
 using the set of nodes given to us in the form of a linked list.
The good thing is that the nodes in the linked list are sorted in ascending order.

As we know, a binary search tree is essentially a rooted binary tree with a very special property or relationship amongst its nodes.
For a given node of the binary search tree,
 it's value must be \ge≥ the value of all the nodes in the left subtree and ≤ the value of all the nodes in the right subtree.
Since a binary tree has a recursive substructure, so does a BST i.e. all the subtrees are binary search trees in themselves.

The main idea in this approach and the next is that:
    the middle element of the given list would form the root of the binary search tree.
    All the elements to the left of the middle element would form the left subtree recursively.
    Similarly, all the elements to the right of the middle element will form the right subtree of the binary search tree.
    This would ensure the height balance required in the resulting binary search tree.
*/
// Time: O(nlogn)
// Space: O(logn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // If the head doesn't exist, then the linked list is empty
        if (head == nullptr) {
          return nullptr;
        }

        // Find the middle element for the list.
        ListNode* mid = findMiddleElement(head);

        // The mid becomes the root of the BST.
        TreeNode* node = new TreeNode(mid->val);

        // Base case when there is just one element in the linked list
        if (head == mid) {
            return node;
        }

        // Recursively form balanced BSTs using the left and right halves of the original list.
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);
        return node;
    }
private:
    ListNode* findMiddleElement(ListNode* head) {
        // The pointer used to disconnect the left half from the mid node.
        ListNode* prevPtr = nullptr;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        // Iterate until fastPr doesn't reach the end of the linked list.
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
          prevPtr = slowPtr;
          slowPtr = slowPtr->next;
          fastPtr = fastPtr->next->next;
        }

        // Handling the case when slowPtr was equal to head.
        if (prevPtr != nullptr) {
          prevPtr->next = nullptr;
        }

        return slowPtr;
    }
        
};

// Approach 2: Recursion + Conversion to Array
// Time: O(n)
// Space: O(n)
class Solution {
public:
    // Solution(){
    //     values = vector<int>();
    // }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
          values.emplace_back(cur->val);
          cur = cur->next;
        }
        return convertListToBST(0, values.size() - 1);
    }
private:
    vector<int> values;
    TreeNode* convertListToBST(int left, int right){
        // Invalid case
        if (left > right) {
          return nullptr;
        }

        // Middle element forms the root.
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(values[mid]);

        // Base case for when there is only one element left in the array
        if (left == right) {
          return node;
        }

        // Recursively form BST on the two halves
        node->left = convertListToBST(left, mid - 1);
        node->right = convertListToBST(mid + 1, right);
        return node;
    }
};

// Approach Approach 3: Inorder Simulation
/*
Intuition:
The inorder traversal on a binary search tree leads to a very interesting outcome.
    Elements processed in the inorder fashion on a binary search tree turn out to be sorted in ascending order.

The critical idea based on the inorder traversal that we will exploit to solve this problem, is:
    We know that the leftmost element in the inorder traversal has to be the head of our given linked list. 
    Similarly, the next element in the inorder traversal will be the second element in the linked list and so on. 
    This is made possible because the initial list given to us is sorted in ascending order.

Algorithm:
1.  Iterate over the linked list to find out it's length. We will make use of two different pointer variables here to mark the beginning and the end of the list. 
    Let's call them start and end with their initial values being 0 and length - 1 respectively.
2.  Remember, we have to simulate the inorder traversal here. We can find out the middle element by using (start + end) / 2. 
    Note that we don't really find out the middle node of the linked list.
    We just have a variable telling us the index of the middle element. 
    We simply need this to make recursive calls on the two halves.
3.  Recurse on the left half by using start, mid - 1 as the starting and ending points.
4.  The invariance that we maintain in this algorithm is that whenever we are done building the left half of the BST, 
     the head pointer in the linked list will point to the root node or the middle node (which becomes the root).
    So, we simply use the current value pointed to by head as the root node and progress the head node by once i.e. head = head.next
5.  We recurse on the right hand side using mid + 1, end as the starting and ending points.
*/
// Time: O(n)
// Space: O(logn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        ListNode* cur = head;
        int len = 0;
        while (cur) {
          ++len;
          cur = cur->next;
        }
        return convertListToBST(0, len - 1);
    }
private:
    ListNode* head;
    TreeNode* convertListToBST(int left, int right){
        // Invalid case
        if (left > right) {
          return nullptr;
        }
        
        int mid = (left + right) / 2;
        
        // stimulate traversing left subtree
        TreeNode* left_node = convertListToBST(left, mid - 1);
        
        TreeNode* node = new TreeNode(head->val);
        node->left = left_node;
        // inorder traverse always iterate the node in ascending order
        // which is same to the order of given ascending linked list
        head = head->next;

        // stimulate traversing right subtree
        node->right = convertListToBST(mid + 1, right);
        return node;
    }
};