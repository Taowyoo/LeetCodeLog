/*
 * File: 161.cpp
 * Created Date: 2021-01-23
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/one-edit-distance/
 * -----
 * Last Modified: 2021-01-23T08:20:21-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */

/**
 * @brief My approach, use two pointer, check from being and end of two strings
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
    bool isOneEditDistance(string& s, string& t, int sl, int sr, int tl, int tr) {
        if(s.empty()&&t.empty()) return false;
        if(s.empty()) return t.size() < 2;
        if(t.empty()) return s.size() < 2;
        while(sl < sr && tl < tr && s[sl] == t[tl]){
            ++sl; ++tl;
            // printf("l\n");
        }
        while(sl < sr && tl < tr && s[sr-1] == t[tr-1]){
            --sr; --tr;
            // printf("r\n");
        }
        int s_len = sr-sl;
        int t_len = tr-tl;
        // printf("%d %d\n",s_len,t_len);
        if(s_len == t_len) return s_len == 1;
        else return abs(s_len-t_len) == 1 && (s_len == 0 || t_len == 0);
    }
public:
    bool isOneEditDistance(string s, string t) {
        return isOneEditDistance(s,t,0,s.size(),0,t.size());
    }
};

