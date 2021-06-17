/*
 * @Author: Nick Cao
 * @Date: 2021-06-16 17:43:57
 * @LastEditTime: 2021-06-16 17:53:58
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @FilePath: /LeetCodeLog/src/3.LongestSubstringWithoutRepeatingCharacters/3.cpp
 */

// Use hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> seen;
        int res = 0;
        for(int l = 0, r = 0; r < s.size();){
            if(seen.find(s[r])!=seen.end() && seen[s[r]]>=l){
                l = seen[s[r]] + 1;
            }
            seen[s[r]]=r;
            ++r;
            if(r-l > res){
                res = r-l;
            }
        }
        return res;
    }
};


// use array when input only contains ascii
class Solution {
     static const int EX_ASCIINUM = 256;
public:
    int lengthOfLongestSubstring(string s) {
        int seen[EX_ASCIINUM];
        memset(seen,-1,EX_ASCIINUM*sizeof(*seen));
        int res = 0;
        for(int l = -1, r = 0; r < s.size(); ++r){
            if(seen[s[r]]>l){
                l = seen[s[r]];
            }
            seen[s[r]]=r;
            if(r-l > res){
                res = r-l;
            }
        }
        return res;
    }
};