// https://leetcode.com/problems/find-peak-element/
// 162. Find Peak Element
// binary search
// Time: O(log2(n))
// Space: O(1)
class Solution {
public:
/**
 * @brief find a peak element in a array
 * 
 * @param nums a array where there is no consecutive equal values
 * @return int 
 */
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // we just need to find one of the peak
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])  // current at right of one peak
                r = mid;
            else  // current at left of one peak
                l = mid + 1;
        }
        return l;
    }

};