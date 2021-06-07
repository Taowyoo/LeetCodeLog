'''
File: 307.py
File Created: 2021-01-12 14:47:18 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/range-sum-query-mutable/
-----
Last Modified: 2021-01-12 14:47:29 -08:00
Modified By: Taowyoo (caoyxsh@outlook.com>)
-----
Copyright 2020 - 2021
'''


class NumArray:

    def __init__(self, nums: List[int]):
        self.preSum = [0] + nums
        self.nums = nums
        self.change = []
        for i in range(1,len(self.preSum)):
            self.preSum[i] += self.preSum[i - 1]
    def update(self, i: int, val: int) -> None:
        self.change.append([i,val - self.nums[i]])
        self.nums[i] = val
        
    def sumRange(self, i: int, j: int) -> int:
        ans = self.preSum[j + 1] - self.preSum[i]
        for pos, val in self.change:
            if pos >= i and pos <= j:
                ans += val
        return ans