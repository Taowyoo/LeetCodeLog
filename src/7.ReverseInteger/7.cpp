/*
 * @Author: Nick Cao
 * @Date: 2021-06-18 12:08:20
 * @LastEditTime: 2021-06-18 12:09:53
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/reverse-integer/
 * @FilePath: /LeetCodeLog/src/7.Reverse Integer/7.cpp
 */

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            if(abs(res) > INT_MAX/10) return 0;
            res = res * 10 + x%10;
            x/=10;
        }
        return res;
    }
};