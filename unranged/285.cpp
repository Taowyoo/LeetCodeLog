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
// inorder traverse and find the successor
class Solution {
    TreeNode* last = nullptr;
    TreeNode* p = nullptr;
    TreeNode* res = nullptr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(last == p) res = root;
        last = root;
        inorder(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        this->p = p;
        inorder(root);
        return res;
    }
};
//====================================================================
// straight forward
// If current node's value is less than or equal to p's value, we know our answer must be in the right subtree.
// If current node's value is greater than p's value, current node is a candidate. Go to its left subtree to see if we can find a smaller one.
// If we reach null, our search is over, just return the candidate.
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = nullptr;
        TreeNode* cur = root;

        while (cur != nullptr) {
            if (cur->val > p->val) {
                candidate = cur;
                cur = cur->left;
            } else {
                // cur.val <= p.val
                cur = cur->right;
            }
        }

        return candidate;
    }
};
//====================================================================
// Iterative Inorder Traversal
// Time: O(Hp)
// Space: O(1)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // the successor is somewhere lower in the right subtree
        // successor: one step right and then left till you can
        if (p->right != nullptr) {
          p = p->right;
          while (p->left != nullptr) p = p->left;
          return p;
        }

        // the successor is somewhere upper in the tree
        stack<TreeNode*> stack;
        int inorder = INT_MIN;

        // inorder traversal : left -> node -> right
        while (!stack.empty() || root != nullptr) {
          // 1-> go left till you can
          while (root != nullptr) {
            stack.push(root);
            root = root->left;
          }

          // 2-> all logic around the node
          root = stack.top();
          stack.pop();
          // if the previous node was equal to p
          // then the current node is its successor
          if (inorder == p->val) return root;
          inorder = root->val;

          // 3-> go one step right
          root = root->right;
        }

        // there is no successor
        return nullptr;
    }
};