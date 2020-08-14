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
// my solution
// use recursion, bottom to top
// Time: O(n)
// Space: O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        addConnect(root->right, root);
        addConnect(root->left, root);
        return root;
    }
private:
    void addConnect(Node* self, Node* parent){
        // nullptr return
        if(!self) return;
        // check whether self is left child
        if(parent->left == self && parent->right){
            self->next = parent->right;
        }
        else{
            // find first no-leaf right neighb of parent
            while(parent->next && !parent->next->left && !parent->next->right) parent = parent->next;
            if(parent->next){
                if(parent->next->left) self->next = parent->next->left;
                else self->next = parent->next->right;
            }
            else{
                
                self->next = nullptr;
            }
        }
        // continue above process on left and right child
        addConnect(self->right, self);
        addConnect(self->left, self);
    }
};
//=================================================================================================================
// Iterate Solution, BFS
class Solution {
public:
    Node* connect(Node* root) {
        Node* head = nullptr; //head of the next level
        Node* prev = nullptr; //the leading node on the next level
        Node* cur = root;  //current node of current level

        while (cur != nullptr) {
            
            while (cur != nullptr) { //iterate on the current level
                //left child
                if (cur->left != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                //right child
                if (cur->right != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                //move to next node
                cur = cur->next;
            }
            
            //move to next level
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
        return root;
    }
};