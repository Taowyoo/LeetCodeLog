// my solution
// use one queue and one vector. 
// Traversal each level at one turn and save each level nodes to vector then put whole vector into the result vector
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
};
//=========================================================================================================
// recursion preoder traversl solution (DFS)
// use a variable to record depth
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        buildVector(root, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());

        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
};