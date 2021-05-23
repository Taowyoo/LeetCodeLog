/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// my solution
class Solution {
private:
    TreeNode* hot_;
    static TreeNode*& searchIn(TreeNode*& root, const int& val, TreeNode*& hot){
        if(!root || root->val == val) return root;
        hot = root;
        while(1){
            TreeNode*& c = (val < hot->val) ? hot->left : hot->right;
            if(!c || c->val == val) return c;
            hot = c;
        }
    }
    TreeNode* getSucc(TreeNode* root, TreeNode*& hot){
        if(root->right){
            hot = root;
            root = root->right;
            while(root->left){
                hot = root;
                root = root->left;
            } 
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*& x = searchIn(root, key, hot_);
        TreeNode* w = x; // record the removed node
        if(!x) return root;
        // remove x
        if(x->left == nullptr){
            x = x->right;
        }
        else if(x->right == nullptr){
            x = x->left;
        }
        else{ // if x has both right and left subtree
            TreeNode* w_parent;
            w = getSucc(x, w_parent);  // find x's successor in inoder
            swap(w->val, x->val);  // swap the data of x's successor and x
            // so original problem transfer to delelet node w (which only has right subtree)
            // should consider maybe w's parent is x
            (w_parent == x ? w_parent->right : w_parent->left) = w->right;  
        }
        // release(w) // release the removed node
        return root;
    }
};
//=====================================================================================================================
// recursion
// Time: O(H)
// Space: O(H)
class Solution {
    int successor(TreeNode* root) {
        root = root->right;
        while (root->left != nullptr) root = root->left;
        return root->val;
    }
    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right != nullptr) root = root->right;
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        // delete from the right subtree
        if (key > root->val) root->right = deleteNode(root->right, key);
        // delete from the left subtree
        else if (key < root->val) root->left = deleteNode(root->left, key);
        // delete the current node
        else {
          // the node is a leaf
          if (root->left == nullptr && root->right == nullptr) root = nullptr;
          // the node is not a leaf and has a right child
          else if (root->right != nullptr) {
            root->val = successor(root);
            root->right = deleteNode(root->right, root->val);
          }
          // the node is not a leaf, has no right child, and has a left child    
          else {
            root->val = predecessor(root);
            root->left = deleteNode(root->left, root->val);
          }
        }
        return root;
    }
};