// my  recursion solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        addConnect(root->left, root);
        addConnect(root->right, root);
        return root;
    }
private:
    void addConnect(Node* self, Node* parent){
        // nullptr return
        if(!self) return;
        // check whether self is left child
        if(parent->right != self){
            self->next = parent->right;
        }
        else{
            // check whether parent is rightmost node at its level
            if(parent->next){
                self->next = parent->next->left;
            }
            else{
                self->next = nullptr;
            }
        }
        // continue above process on left and right child
        addConnect(self->left, self);
        addConnect(self->right, self);
    }
    
};
//========================================================================================
// iterate solution
void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = nullptr;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}