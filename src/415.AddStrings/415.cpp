/*
 * @Author: Nick Cao
 * @Date: 2021-03-25 12:42:06
 * @LastEditTime: 2021-06-18 12:14:40
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/add-strings/
 * @FilePath: /LeetCodeLog/src/415.AddStrings/415.cpp
 */

// my solution
// time: O(n)
// memory: O(n)
class Solution {
public:
  string addStrings(string num1, string num2) {
    string s = "";
    // iterate from end of two string
    int c = 0, i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0 || c > 0) {
      c += i >= 0 ? num1[i--] - '0' : 0;
      c += j >= 0 ? num2[j--] - '0' : 0;
      // store number in reverse order
      s += char(c % 10 + '0');
      c /= 10;
    }
    // reverse tmp result to correct order
    reverse(s.begin(), s.end());
    return s;
  }
};