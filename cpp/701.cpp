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
// my solution using a general search function
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto& x = searchIn(root, val, hot_);
        if(!x){
            x = new TreeNode(val);
        } 
        return root;
    }
};
//=====================================================================================================================
// recursion
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        // insert into the right subtree
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        // insert into the left subtree
        else root->left = insertIntoBST(root->left, val);
        return root;
    }
};
//=====================================================================================================================
// iterate simple
// Time: O(H)
// Space: O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while (node != nullptr) {
          // insert into the right subtree
          if (val > node->val) {
            // insert right now
            if (node->right == nullptr) {
              node->right = new TreeNode(val);
              return root;
            }
            else node = node->right;
          }
          // insert into the left subtree
          else {
            // insert right now
            if (node->left == nullptr) {
              node->left = new TreeNode(val);
              return root;
            }
            else node = node->left;
          }
        }
        return new TreeNode(val);
    }
};