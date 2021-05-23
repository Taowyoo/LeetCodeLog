// my solution with my self-designed BST
// Time: O(N*H)
// Space: O(N)
class KthLargest {
    struct TreeNode {
        int val;
        int cnt = 1;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    TreeNode* root_ = nullptr; 
    TreeNode* hot_ = nullptr; 
    int k_;
	// hot_ will always be the parent of searchIn result or we end search if not found
    static TreeNode*& searchIn(TreeNode*& root, const int& val, TreeNode*& hot){
        if(!root || root->val == val) return root;
        hot = root;
        while(1){
            ++hot->cnt;
            TreeNode*& c = (val < hot->val) ? hot->left : hot->right;
            if(!c || c->val == val) return c;
            hot = c;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
		return searchIn(root, val, hot_);
	}
	TreeNode* insertIntoBST(TreeNode*& root, int val) {
		auto& x = searchIn(root, val, hot_);
		if(!x){
			x = new TreeNode(val);
		}
        else{
            ++x->cnt;
            TreeNode* tmp = x->left;
            x->left = new TreeNode(val);
            x->left->left = tmp;
            x->left->cnt += tmp == nullptr ? 0 : tmp->cnt;
        }
		return root;
	}
    int getKthLargestNode(TreeNode* cur, int k){
        while(k > 1){
            if(cur->right){
                if(cur->right->cnt < k){
                    k -= cur->right->cnt;
                    if(k == 1) return cur->val;
                    --k;
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                }
            }
            else{
                --k;
                cur = cur->left;
            }
        }
        if(k == 1){
            while(cur->right) cur = cur->right;
        }
        return cur->val;
    }
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int num : nums){
            insertIntoBST(root_, num);
        }
        
    }
    
    int add(int val) {
        insertIntoBST(root_, val);
        return getKthLargestNode(root_, k_);
    }
};
//====================================================================================================
// use priority_queue
class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

