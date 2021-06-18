/*
 * @Author: Nick Cao
 * @Date: 2021-06-16 18:15:59
 * @LastEditTime: 2021-06-16 18:16:09
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/valid-parentheses/
 * @FilePath: /LeetCodeLog/src/20. Valid Parentheses/20.cpp
 */

class Solution {
public:
    bool isValid(string s) {
        int idx = 0;
        vector<char> stack;
        for(char ch : s){
            switch(ch){
                case ')':
                    if(!stack.empty()&&stack.back()=='(') stack.pop_back();
                    else return false;
                    break;
                case ']':
                    if(!stack.empty()&&stack.back()=='[') stack.pop_back();
                    else return false;
                    break;
                case '}':
                    if(!stack.empty()&&stack.back()=='{') stack.pop_back();
                    else return false;
                    break;
                default:
                    stack.push_back(ch);
            }
        }
        return stack.empty();
    }
};