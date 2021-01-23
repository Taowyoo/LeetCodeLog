/*
 * File: 16.cpp
 * Created Date: 2021-01-23
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/3sum-closest/
 * -----
 * Last Modified: 2021-01-23T08:28:12-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */

/**
 * @brief Approach 1: Two Pointers
 * Time: O(n^2)
 * Space: O(log(n)) to O(n), depending on the implementation of the sorting algorithm
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1, hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    ++lo;
                else
                    --hi;
            }
        }
        return target - diff;
    }
};

/**
 * @brief Approach 2: Binary Search
 * Time: O(n^2log(n))
 * Space: O(log(n)) to O(n), depending on the implementation of the sorting algorithm
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                auto it = upper_bound(begin(nums) + j + 1, end(nums), complement);
                int hi = it - begin(nums), lo = hi - 1;
                if (hi < sz && abs(complement - nums[hi]) < abs(diff))
                    diff = complement - nums[hi];
                if (lo > j && abs(complement - nums[lo]) < abs(diff))
                    diff = complement - nums[lo];
            }
        }
        return target - diff;
    }
};