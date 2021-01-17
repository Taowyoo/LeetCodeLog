'''
File: 1.py
File Created: 2021-01-04 20:01:58 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/two-sum/
-----
Last Modified: 2021-01-04 21:03:19 -08:00
Modified By: Taowyoo (caoyxsh@outlook.com>)
-----
Copyright 2020 - 2021
'''

class Solution1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """One pass using HashMap

        Args:
            nums (List[int]): number list
            target (int): target sum

        Returns:
            List[int]: the index of two result nums
        """
        d = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in d:
                return [d[m], i]
            else:
                d[n] = i



class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
            """Two pass using HashMap

            Args:
                nums (List[int]): number list
                target (int): target sum

            Returns:
                List[int]: the index of two result nums
            """
            d = {}
            for i, n in enumerate(nums):
                d[n]=i
                
            for i, n in enumerate(nums):
                m = target - n
                if m in d and d[m] != i:
                    return [i,d[m]]
            return []