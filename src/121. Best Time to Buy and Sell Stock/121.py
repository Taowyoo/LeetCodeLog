'''
Author: Nick Cao
Date: 2021-06-06 12:04:39
LastEditTime: 2021-06-06 12:12:18
LastEditors: Nick Cao
Description: 
FilePath: \LeetCodeLog\src\121. Best Time to Buy and Sell Stock\121.py
'''

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = 10**5
        profit = 0
        for x in prices:
            if x < min_price:
                min_price = x
            elif x - min_price > profit:
                profit = x - min_price
        return profit