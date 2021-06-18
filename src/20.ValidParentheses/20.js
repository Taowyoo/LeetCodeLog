/*
 * @Author: Nick Cao
 * @Date: 2021-06-16 18:17:48
 * @LastEditTime: 2021-06-16 18:17:49
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/valid-parentheses/
 * @FilePath: /LeetCodeLog/src/20. Valid Parentheses/20.js
 */

var isValid = function(s) {   
    const stack = [];
    
    for (let i = 0 ; i < s.length ; i++) {
        let c = s.charAt(i);
        switch(c) {
            case '(': stack.push(')');
                break;
            case '[': stack.push(']');
                break;
            case '{': stack.push('}');
                break;
            default:
                if (c !== stack.pop()) {
                    return false;
                }
        }
    }
    
    return stack.length === 0;
};
