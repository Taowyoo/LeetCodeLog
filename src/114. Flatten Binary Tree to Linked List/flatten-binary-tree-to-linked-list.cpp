/*
 * File: flatten-binary-tree-to-linked-list.cpp
 * File Created: 2021-01-15 12:44:37 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * -----
 * Last Modified: 2021-01-15 13:29:14 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

// 114. Flatten Binary Tree to Linked List

// my solution
// recursively process subbranchs and move left branch to right branch
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
/**
 * @brief Flatten a binary tree.
 * 
 * @param root Root node of binary tree
 */
void flatten(TreeNode* root) {
    process(root);
}

// improved approach (same idea)
// Time: O(N)
// Space: O(N)
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
/**
 * @brief Flatten a binary tree.
 * 
 * @param root Root node of binary tree
 */
void flatten(TreeNode* root) {
    this->flattenTree(root);
}


/**
 * @brief Iterative solution
 * 
 */
class Solution {
    
    private TreeNode flattenTree(TreeNode node) {
        
        // Handle the null scenario
        if (node == null) {
            return null;
        }
            
        // For a leaf node, we simply return the
        // node as is.
        if (node.left == null && node.right == null) {
            return node;
        }
        
        //Recursively flatten the left subtree
        TreeNode leftTail = this.flattenTree(node.left);
        
        // Recursively flatten the right subtree
        TreeNode rightTail = this.flattenTree(node.right);
        
        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != null) {
            leftTail.right = node.right;
            node.right = node.left;
            node.left = null;
        }
        
        // We need to return the "rightmost" node after we are
        // done wiring the new connections. 
        return rightTail == null ? leftTail : rightTail;
    }
    
    public void flatten(TreeNode root) {
        
        this.flattenTree(root);
    }
}