/*
 * File: maximum-depth-of-binary-tree.cpp
 * File Created: 2021-01-15 12:44:40 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * -----
 * Last Modified: 2021-01-15 13:20:58 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

// 104. Maximum Depth of Binary Tree

// recursion solution
// using DFS
/**
 * @brief Recursively get max depth.
 * 
 * @param root Current Node
 * @return int The depth of tree whose root is current Node
 */
int maxDepth(TreeNode* root) {
    return root == nullptr ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
//=========================================================================================================
// BFS
/**
 * @brief BFS to get max depth
 * 
 * @param root Current Node
 * @return int The depth of tree whose root is current Node
 */
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;

    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();

            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }

    return res;
}
