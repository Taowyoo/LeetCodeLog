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
// Recursive Inorder + Linear search, O(N) time
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        // go deep according to the relation between val and target
        TreeNode* cur = root;
        int closest = cur->val;
        // bigger, go left
        while(cur){
            if(abs(cur->val - target) < abs(closest - target)) closest = cur->val;
            if(double(cur->val) > target){
                cur = cur->left;
            }
            else if (double(cur->val) < target){
                cur = cur->right;
            }
            else{
                return cur->val;
            }
        }
        // smaller, go right
        return closest;
    }
};