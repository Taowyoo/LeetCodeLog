'''
File: 539.py
Created Date: 2021-03-08
Author: Nick Cao(caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/minimum-time-difference/
-----
Last Modified: 2021-03-08T10:41:07-08:00
Modified By: Nick Cao(caoyxsh@outlook.com)
'''
from typing import List

class Solution:
	"""
	Using Sort
	"""
	def findMinDifference(self, timePoints: List[str]) -> int:
        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])
        minutes = list(map(convert, timePoints))
        minutes.sort()
        return min( (y - x) % (24 * 60) 
                    for x, y in zip(minutes, minutes[1:] + minutes[:1]) )