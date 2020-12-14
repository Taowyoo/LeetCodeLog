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
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// my solution
// inorder traverse the BST, and build a linked list in inorder by using the 'left' node
// Time: O(n)
// Space: O(1)
class BSTIterator {
    TreeNode* last = nullptr;
    TreeNode* head = nullptr;
    TreeNode* cur = nullptr;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        // init head
        if(!head->left) head->left = root;
        // use left as next
        if(last) last->left = root;
        last = root;
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        head = new TreeNode();
        inorder(root);
        if(last) last->left = nullptr;
        cur = head;
    }
    
    /** @return the next smallest number */
    int next() {
        int res = 0;
        if(cur->left) res = cur->left->val;
        cur = cur->left;
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur->left != nullptr;
    }
};
//===============================================================================
// Flattening the BST
// Time: O(N)
// Space: O(N)
class BSTIterator {
    vector<int> nodesSorted;
    int index;
    void _inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        _inorder(root->left);
        nodesSorted.emplace_back(root->val);
        _inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        // Pointer to the next smallest element in the BST
        index = -1;
        
        // Call to flatten the input binary search tree
        _inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return nodesSorted.at(++index);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index + 1 < nodesSorted.size();
    }
};
//===============================================================================
// Controlled Recursion
// stimulate the iteration of inorder traversal
class BSTIterator {
    stack<TreeNode*> stack;
    void _leftmostInorder(TreeNode* root) {
        // For a given node, add all the elements in the leftmost branch of the tree
        // under it to the stack.
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        _leftmostInorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        // Node at the top of the stack is the next smallest element
        TreeNode* topmostNode = stack.top();
        stack.pop();

        // Need to maintain the invariant. If the node has a right child, call the 
        // helper function for the right child
        if (topmostNode->right != nullptr) {
            _leftmostInorder(topmostNode->right);
        }

        return topmostNode->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
         return stack.size() > 0;
    }
};