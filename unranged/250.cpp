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
// DFS with backtracing, check each subtree from down to top
// Time: O(n), let n is number of nodes
// Space:O(H), let H is height of whole tree
class Solution {
    bool isUnival(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr){
            ++count;
            
            return true;
        }
        if(root->left == nullptr || root->right == nullptr){
            TreeNode* sub = root->left != nullptr ? root->left : root->right;
            
            if(isUnival(sub) && sub->val == root->val){
                ++count;
                return true;
            }
            else return false;
        }
        bool le = isUnival(root->left);
        bool ri = isUnival(root->right);
        if(le && ri && root->right->val == root->left->val && root->right->val == root->val){
            ++count;
            return true;
        }
        else
            return false;
    }
    int count = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        isUnival(root);
        return count;
    }
};
//===================================================================================================
// Depth First Search - Pass Parent Values
// Time: O(n), let n is number of nodes
// Space:O(H), let H is height of whole tree
class Solution {
    bool isUnival(TreeNode* root, int val){
        // considered a valid subtree
        if (root == nullptr) return true;

        // check if node.left and node.right are univalue subtrees of value node.val
        // note that || short circuits but | does not - both sides of the or get evaluated with | so we explore all possible routes
        if (!isUnival(root->left, root->val) | !isUnival(root->right, root->val)) return false;

        // if it passed the last step then this a valid subtree - increment
        count++;

        // at this point we know that this node is a univalue subtree of value node.val
        // pass a boolean indicating if this is a valid subtree for the parent node
        return root->val == val;
    }
    int count = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        isUnival(root,0);
        return count;
    }
};
