/*
 * File: 1.cpp
 * File Created: 2021-01-04 20:06:42 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/two-sum/
 * -----
 * Last Modified: 2021-01-04 21:02:05 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

class Solution1 {
public:
    /**
     * @brief Use hashmap with one pass
     * 
     * @param nums Number list
     * @param target Target value
     * @return vector<int> Number pair found
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        int cur = 0;
        unordered_map<int,int> is_finding;
        while(cur < nums.size()){
            auto search = is_finding.find(nums[cur]);
            if(search != is_finding.end()){
                return vector<int>{search->second,cur};
            }
            // Add current values as an existed pair
            // So future number may pair with this number
            // So one pass is enough
            is_finding[target - nums[cur]] = cur;
            ++cur;
        }
        throw std::runtime_error("Error: No Solution!");
    }
};



class Solution2 {
public:
    /**
     * @brief Use hashmap with two pass
     * 
     * @param nums Number list
     * @param target Target value
     * @return vector<int> Number pair found
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement) && map[complement] != i) {
                return vector<int>{i, map[complement]};
            }
        }
        throw std::runtime_error("Error: No Solution!");
    }
};