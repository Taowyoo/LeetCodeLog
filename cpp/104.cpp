// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// 104. Maximum Depth of Binary Tree

// recursion solution
// using DFS
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
class Solution {
public:
/**
 * @brief Recursively get max depth.
 * 
 * @param root Current Node
 * @return int The depth of tree whose root is current Node
 */
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};
//=========================================================================================================
// BFS
class Solution {
public:
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
};