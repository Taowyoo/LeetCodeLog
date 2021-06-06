/*
 * File: binary-tree-level-order-traversal.cpp
 * File Created: 2021-01-15 12:44:27 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * -----
 * Last Modified: 2021-01-15 13:20:39 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

// 102. Binary Tree Level Order Traversal

// my solution
// use one queue and one vector.
// Traversal each level at one turn and save each level nodes to vector then put whole vector into the result vector
/**
 * @brief Get nodes in levelOrder of a Tree.
 * 
 * @param root Root node pointer
 * @return vector<vector<int>> Lists of nodes of each level
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> todo;
    todo.emplace(root);
    vector<int> level;
    while(!todo.empty()){
        int num = todo.size();
        for(int i = 0; i < num; ++i){
            auto first = todo.front();
            level.emplace_back(first->val);
            if(first->left) todo.emplace(first->left);
            if(first->right) todo.emplace(first->right);
            todo.pop();
        }
        res.emplace_back(level);
        level.clear();
    }
    return res;
}

//=========================================================================================================
// recursion preoder traversl solution (DFS)
// use a variable to record depth
/**
 * @brief Get nodes in levelOrder of a Tree.
 * 
 * @param root Root node pointer
 * @return vector<vector<int>> Lists of nodes of each level
 */
vector<vector<int>> levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}
vector<vector<int>> ret;
/**
 * @brief Recursive function to traverse nodes in preorder
 * use a variable depth to record current depth
 * @param root Current Node pointer
 * @param depth Curent Node depth
 */
void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}
