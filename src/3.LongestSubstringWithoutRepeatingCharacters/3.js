/*
 * @Author: Nick Cao
 * @Date: 2021-06-16 17:12:10
 * @LastEditTime: 2021-06-16 17:27:11
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @FilePath: /LeetCodeLog/src/3.LongestSubstringWithoutRepeatingCharacters/3.js
 */

/**
 * Use Map
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let seen = new Map();
    let l = 0, r = 0;
    let res = 0;
    while (r < s.length) {
        if (seen.has(s[r])) {
            last = seen.get(s[r]);
            if (last >= l) {
                l = last + 1;
            }
        }
        seen.set(s[r], r);
        r++;
        if (r - l > res) {
            res = r - l;
        }
    }
    return res;
};


/**
 * Use array, asuming input string only contains ascii
 * @param {string} s
 * @return {number}
 */
 var lengthOfLongestSubstring = function(s) {
    let seen = new Array(256);
    let l = 0, r = 0;
    let res = 0;
    while (r<s.length){
        if (seen[s.charCodeAt(r)]!=null){
            last = seen[s.charCodeAt(r)];
            if(last >= l){
                l = last + 1;
            }
        }
        seen[s.charCodeAt(r)]=r;
        r++;
        if(r-l >res){
            res = r-l;
        }
    }
    return res;
};