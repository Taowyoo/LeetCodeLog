// my solution
// recrusive solution using iterator to mark subtree bound
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
typedef decltype(std::begin(std::vector<int>())) vit;
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        vit in_l, vit in_r, vit post_l, vit post_r){
        if(in_l >= in_r || post_l >= post_r) return nullptr;
        auto root_it = post_r - 1;
        TreeNode* root = new TreeNode(*root_it);
        auto root_it_inorder = find(in_l, in_r, *root_it);
        int left_len = root_it_inorder - in_l;
        root->left = buildTree(inorder, postorder, in_l, root_it_inorder, post_l, post_l + left_len);
        root->right = buildTree(inorder, postorder, root_it_inorder + 1, in_r, post_l + left_len, post_r - 1);
        return root;
    }
};
//=========================================================================================================
// recrusive solution using int to mark subtree bound
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
private:
    TreeNode* create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe){
        if(ps > pe){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[pe]);
        int pos;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
        node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
        return node;
    }
};


