// my solution
// use two binary search to find the First and Last Position
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // corner cases
        if(nums.empty() || target < nums.front() || target > nums.back()) return vector<int>{-1,-1};
        // find right bound
        int lo = 0, hi = nums.size();
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        int right = lo - 1;
        // check whether found target
        if(right < 0 || right == nums.size() || nums[right] != target) return vector<int>{-1,-1};
        // find left bound
        lo = 0, hi = nums.size();
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > target - 1) hi = mid;
            else lo = mid + 1;
        }
        return vector<int>{lo, right};
    }
};