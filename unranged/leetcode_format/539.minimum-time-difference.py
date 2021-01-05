#
# @lc app=leetcode id=539 lang=python3
#
# [539] Minimum Time Difference
#

# @lc code=start
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])
        minutes = list(map(convert, timePoints))
        minutes.sort()
        return min( (y - x) % (24 * 60) 
                    for x, y in zip(minutes, minutes[1:] + minutes[:1]) )
# @lc code=end

