// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 153. Find Minimum in Rotated Sorted Array

// Binary search
// Description: by comparing the mid and last to find the real beginning(min)
// Time: O(log(n))
// Space: O(1)
class Solution {
public:
    /**
     * @brief find the Minimum in a sorted array which is rotated at some pivot unknown
     * 
     * @param nums sorted array which is rotated at some pivot unknown
     * @return int the minimal number in the array
     */
    int findMin(vector<int>& nums) {
        // find the start index which is also the Minimum
        // find in [0,hi]
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            // by comparing to the rightmost number in the range
            // we could determine whether current index is left or right to pivot
            if(nums[mid] > nums[hi]) lo = mid + 1;  // if bigger, then we are now left to pivot
            else hi = mid;  // if <=, we are now right to pivot
        }
        // at end, we will reach the pivot which also is minimal number
        return nums[lo];
    }
};