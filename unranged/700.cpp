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
// my solution
// iterate with a general searchIn function
// Time: O(H)
// Space: O(1)
class Solution {
    TreeNode* hot_;
    static TreeNode*& searchIn(TreeNode*& root, const int& val, TreeNode*& hot){
        if(!root || root->val == val) return root;
        hot = root;
        while(1){
            TreeNode*& c = (val < hot->val) ? hot->left : hot->right;
            if(!c || c->val == val) return c;
            hot = c;
        }
    }      
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchIn(root, val, hot_);
    }
};
//=====================================================================================
// Simple iterate
// Time: O(H)
// Space: O(1)
class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    while (root != nullptr && val != root->val)
      root = val < root->val ? root->left : root->right;
    return root;
  }
};
//=====================================================================================
// recursion
// Time: O(H)
// Space: O(H)
class Solution {     
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || val == root->val) return root;
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};