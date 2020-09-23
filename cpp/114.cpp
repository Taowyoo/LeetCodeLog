// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// 114. Flatten Binary Tree to Linked List

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
// recursively process subbranchs and move left branch to right branch
class Solution {
    /**
     * @brief Flatten the current given tree and return right most leaf
     * 
     * @param root The root node of given tree
     * @return TreeNode* right most leaf
     */
    TreeNode* process(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* r_subT = root->right;
        TreeNode* l_subT_r_bottom =  process(root->left);
        
        if(l_subT_r_bottom != nullptr){
            root->right = root->left;
            root->left = nullptr;
            l_subT_r_bottom->right = r_subT;
        }
        TreeNode* r_subT_r_bottom = process(r_subT);
        return r_subT_r_bottom ? r_subT_r_bottom : (l_subT_r_bottom ? l_subT_r_bottom : root);
    }
public:
    /**
     * @brief Flatten a binary tree.
     * 
     * @param root Root node of binary tree
     */
    void flatten(TreeNode* root) {
        process(root);
    }
};

// improved approach (same idea)
class Solution {
    /**
     * @brief Flatten the current given tree and return right most leaf
     * 
     * @param root The root node of given tree
     * @return TreeNode* right most leaf
     */
    TreeNode* flattenTree(TreeNode* node) {
        
        // Handle the nullptr scenario
        if (node == nullptr) {
            return nullptr;
        }
            
        // For a leaf node, we simply return the
        // node as is.
        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }
        
        //Recursively flatten the left subtree
        TreeNode* leftTail = this->flattenTree(node->left);
        
        // Recursively flatten the right subtree
        TreeNode* rightTail = this->flattenTree(node->right);
        
        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != nullptr) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        
        // We need to return the "rightmost" node after we are
        // done wiring the new connections. 
        return rightTail == nullptr ? leftTail : rightTail;
    }
public:
    /**
     * @brief Flatten a binary tree.
     * 
     * @param root Root node of binary tree
     */
    void flatten(TreeNode* root) {
        this->flattenTree(root);
    }
};