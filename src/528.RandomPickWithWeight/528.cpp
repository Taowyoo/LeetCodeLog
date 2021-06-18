/*
 * @Author: Nick Cao
 * @Date: 2021-06-18 13:30:07
 * @LastEditTime: 2021-06-18 13:37:48
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/random-pick-with-weight/
 * @FilePath: /LeetCodeLog/src/528.RandomPickWithWeight/528.cpp
 */

/**
 * @brief Prefix Sums with Binary Search
 * 
 */
class Solution {
public:
    int weights_sum;
    vector<int> weights_count;
    /**
     * @brief Construct a new Solution object
     * Time: O(N)
     * Space: O(N)
     * @param w Given weights array
     */
    Solution(vector<int>& w) {
        weights_count.emplace_back(w[0]);
        for(int i = 1 ; i < w.size(); ++i){
            weights_count.emplace_back(weights_count[i - 1] + w[i]);
        }
        weights_sum = weights_count.back();
    }

    /**
     * @brief Produce weighted random number
     * Time: O(log(N))
     * Space: O(1)
     * @return int Weighted random number
     */
    int pickIndex() {
        int x = rand() % weights_sum;
        return  b_search(weights_count,x);
    }
    /**
     * @brief Use binary search on Prefix Sums array of weights to get the number
     * 
     * @param arr Prefix Sums array of weights
     * @param val The random number in range: [0,weights_sum)
     * @return int Weighted random number
     */
    int b_search(vector<int>& arr,int val){
        int hi = arr.size();
        int lo = 0;
        while(lo<hi){
            int mid = (lo + hi) >> 1;
            if(arr[mid] > val) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */