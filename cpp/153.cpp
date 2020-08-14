// binary search
// by comparing the mid and last to find the real beginning(min)
class Solution {
public:
    int findMin(vector<int>& nums) {
        // find the start index
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }
};