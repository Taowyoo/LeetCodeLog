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
// use recursion
// Time: O(n)
// Space: O(logn)~O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int pre_l, int pre_r, int in_l, int in_r){
        if(in_l > in_r || pre_l > pre_r) return nullptr;
        int val = preorder[pre_l];
        auto root = new TreeNode(val);
        if(in_l == in_r || pre_l == pre_r) return root;
        int l_len = find(inorder.begin() + in_l, inorder.begin() + in_r, val) - (inorder.begin() + in_l);
        root->left = buildTree(preorder, inorder, pre_l + 1, pre_l + l_len, in_l, in_l + l_len - 1);
        root->right = buildTree(preorder, inorder, pre_l + l_len + 1, pre_r, in_l + l_len + 1, in_r);
        return root;
    }
};
//=======================================================================================================
// iterate solution
class Solution {
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &in) {
        int i=0,j=0;
        TreeNode *root=new TreeNode(0x80000000);
        TreeNode *pp=NULL,*ptr=root;
        stack<TreeNode*> sn;sn.push(root);
        while (j<in.size()) {
            if (sn.top()->val==in[j]) {
                pp=sn.top();
                sn.pop();
                j++;
            } else if (pp) {
                ptr=new TreeNode(pre[i]);
                pp->right=ptr;pp=NULL;
                sn.push(ptr);
                i++;
            } else {
                ptr=new TreeNode(pre[i]);
                sn.top()->left=ptr;
                sn.push(ptr);
                i++;
            }
        }
        ptr=root->left;delete root;
        return ptr;
    }
}; 