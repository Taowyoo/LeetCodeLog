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
// my solution: use inorder traversal to check
class Solution {
    bool res = true;
    int last = INT_MIN;
    bool begin = true;
    void process(TreeNode* root){
        if(!root) return;
        process(root->left);
        if(begin){
            last = root->val;
            begin = false;
        } 
        else{
        if(root->val <= last) res = false;
        last = root->val;}
        process(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        process(root);
        return res;
    }
    
};
//==========================================================================================
// iterate inorder
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sta;
        double inorder = - std::numeric_limits<double>::max();

        while (!sta.empty() || root != nullptr) {
          while (root != nullptr) {
            sta.push(root);
            root = root->left;
          }
          root = sta.top();
          sta.pop();
          // If next element in inorder traversal
          // is smaller than the previous one
          // that's not BST.
          if (root->val <= inorder) return false;
          inorder = root->val;
          root = root->right;
        }
        return true;
    }
    
};
//==========================================================================================
Recursion