// my solution
// Time: O(n)
// Space: O(n)
// use a variable to record depth, and make rescursion that return from bottom to top
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca_ = root;
        depth_ = 0;
        findLCA(root, p, q, 0);
        return lca_;
    }
private:
    TreeNode* lca_;
    int depth_;
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q, int depth){
        if(!root) return nullptr;
        TreeNode* le = findLCA(root->left, p, q, depth + 1);
        TreeNode* ri = findLCA(root->right, p, q, depth + 1);
        if(root == p || root == q){
            if(le || ri) {
                if(depth > depth_){
                    lca_ = root;
                    depth_ = depth;
                }
            }
            return root;
        }
        if(le && ri){
            if(depth > depth_){
                lca_ = root;
                depth_ = depth;
            }
            return root;
        }
        if(!ri && !le) return nullptr;
        return root;
    }
};
//========================================================================================
// Recursion Better Solution
// Time: O(n)
// Space: O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
}
//========================================================================================
// Iteration Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //iterative, path comparing
        if(!root || root==p || root==q) return root;
        vector<TreeNode*> pathp, pathq, temp;
        temp.push_back(root);
        TreeNode* prev=NULL;
        while(pathp.empty() || pathq.empty()){
            root=temp.back();
            if(root==p) pathp=temp;
            if(root==q) pathq=temp;
            if(!root->left && !root->right || !root->right && prev==root->left || root->right && prev==root->right){
                temp.pop_back();
                prev=root;
            }
            else{
                if(!root->left || prev==root->left) temp.push_back(root->right);
                else temp.push_back(root->left);
            }
        }
        int n=min(pathp.size(),pathq.size());
         for(int i=1; i<n; i++){
            if(pathp[i]!=pathq[i]) return pathp[i-1];
        }
        return pathp[n-1];
    }
};