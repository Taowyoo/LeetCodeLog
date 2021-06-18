/*
 * @Author: Nick Cao
 * @Date: 2021-06-18 13:02:19
 * @LastEditTime: 2021-06-18 13:11:48
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * @FilePath: /LeetCodeLog/src/215.KthLargestElementInAnArray/215.cpp
 */

/**
 * @brief PQ
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i< k; i++){
            heap.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            heap.push(nums[i]);
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * @brief Min-Heap
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        for(int i = 0; i< k; i++){
            heap.push_back(nums[i]);
        }
        make_heap(heap.begin(), heap.end(),std::greater<>{});
        for(int i = k; i < nums.size(); i++){
            heap.push_back(nums[i]);
            push_heap(heap.begin(), heap.end(),std::greater<>{});
            std::pop_heap(heap.begin(), heap.end(),std::greater<>{});
            heap.pop_back();
        }
        return heap[0];
    }
};