// binary search with 3 branches
// Time: O(logn)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le = 0;
        int ri = nums.size();
        
        while(le < ri){
            int mid = (le + ri) >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                le = mid + 1;
            else
                ri = mid;
        }
        return -1;
    }
};
//=====================================================================
