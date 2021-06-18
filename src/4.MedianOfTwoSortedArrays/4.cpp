/*
 * @Author: Nick Cao
 * @Date: 2021-06-16 18:09:52
 * @LastEditTime: 2021-06-16 18:09:52
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * @FilePath: /LeetCodeLog/src/4.Median of Two Sorted Arrays/4.cpp
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure vector 1 is the shorter one.
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);	
        int length1 = nums1.size();
        int length2 = nums2.size();

        int low = 0, high = length1;
        while (low <= high) {
            int mid1 = (low + high) / 2;   // Get Cut 1
            int mid2 = (length1 + length2 + 1) / 2 - mid1;  // Calculate Cut 2

            double maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];	
            double minRight1 = (mid1 == length1) ? INT_MAX : nums1[mid1];
            
            double maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            double minRight2 = (mid2 == length2) ? INT_MAX : nums2[mid2];

            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1){
                if((length1 + length2) % 2 == 0){
                    return ((double)max(maxLeft1, maxLeft2) + min(minRight1, minRight2))/2;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if(maxLeft1 > minRight2){
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};