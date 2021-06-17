'''
Author: Nick Cao
Date: 2021-06-16 17:54:07
LastEditTime: 2021-06-16 17:59:32
LastEditors: Nick Cao
Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/
FilePath: /LeetCodeLog/src/3.LongestSubstringWithoutRepeatingCharacters/3.PY
'''


'''
@description: Use map
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        # mp stores the current index of a character
        mp = {}

        i = 0
        # try to extend the range [i, j]
        for j in range(n):
            if s[j] in mp:
                i = max(mp[s[j]], i)

            ans = max(ans, j - i + 1)
            mp[s[j]] = j + 1

        return ans