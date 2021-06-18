/*
 * @Author: Nick Cao
 * @Date: 2021-06-18 12:31:09
 * @LastEditTime: 2021-06-18 12:36:38
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/decode-ways/
 * @FilePath: /LeetCodeLog/src/91.DecodeWays/91.cpp
 */

/**
 * @brief Recursive Approach with Memoization
 * Space: O(N)
 * Time: O(N)
 */
class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }
        // check one digit
        int ans = recursiveWithMemo(index + 1, str);
        // check two digits
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s) {
        return recursiveWithMemo(0, s);
    }
};

/**
 * @brief Iterative Approach
 * Space: O(N)
 * Time: O(N)
 */
class Solution {
public:
    int numDecodings(string s) {
        // DP array to store the subproblem results
        vector<int> dp(s.length() + 1);
        dp[0] = 1;

        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s[0] == '0' ? 0 : 1;

        for (size_t i = 2; i < dp.size(); i++) {
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int two_digit = stoi(s.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};

/**
 * @brief Iterative, Constant Space
 * Space: O(N)
 * Time: O(1)
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (size_t i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 and two_digit <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }
        return one_back;
    }
};