// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 34. Find First and Last Position of Element in Sorted Array

// my solution
// use binary search twice to find the First and Last Position
// Time: O(log(n))
// Space: O(1)
class Solution {
public:
    /**
     * @brief find the range of specific target number in a sorted array
     * 
     * @param nums sorted array in ascending order
     * @param target target number that want to be searched
     * @return vector<int> the range of target number, if no found return {-1,-1}
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        // corner cases
        if(nums.empty() || target < nums.front() || target > nums.back()) return vector<int>{-1,-1};
        // find right bound
        int lo = 0, hi = nums.size();
        // find the index of first element that bigger tha target
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        // so after search, the target is supposed to at lo - 1
        int right = lo - 1;
        // check whether found target
        if(right < 0 || right == nums.size() || nums[right] != target) return vector<int>{-1,-1};
        // find left bound
        lo = 0, hi = nums.size();
        // so use same mechanism to find the first element that bigger than target - 1
        // which is exactly the left bound 
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > target - 1) hi = mid;
            else lo = mid + 1;
        }
        return vector<int>{lo, right};
    }
};