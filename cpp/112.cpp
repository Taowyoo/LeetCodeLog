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
// my slolution
// recrusion solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int cur_sum = 0;
        return hasPathSum(root, sum, cur_sum);
    }
private:
    bool hasPathSum(TreeNode* root, int sum, int cur_sum) {
        if(!root) return false;
        cur_sum += root->val;
        if(root->left || root->right)
            return hasPathSum(root->left, sum, cur_sum) || hasPathSum(root->right, sum, cur_sum);
        else
            return cur_sum == sum;
    }
};
//=========================================================================================================
// iterate solution using postorder
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        stack<TreeNode *> s;
        TreeNode *pre = NULL, *cur = root;
        int SUM = 0;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                SUM += cur->val;
                cur = cur->left;
            }
            cur = s.top();
            if (cur->left == NULL && cur->right == NULL && SUM == sum) {
                return true;
            }
            if (cur->right && pre != cur->right) {
                cur = cur->right;
            } else {
                pre = cur;
                s.pop();
                SUM -= cur->val;
                cur = NULL;
            }
        }
        return false;
    }
};