import java.util.HashMap;

/*
 * @lc app=leetcode id=91 lang=java
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.76%)
 * Likes:    3099
 * Dislikes: 3119
 * Total Accepted:    439.7K
 * Total Submissions: 1.8M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
// my recursion solution
class Solution {
    private HashMap<String, Integer> memo;  // HashMap tp store checked string
    /**
     * Get the number of ways to decode given String
     * @param s Given string
     * @return The total number of ways to decode the given string
     */
    private int count(String s){
        // if checked before, return its result
        if(memo.containsKey(s)){
            return memo.get(s);
        }
        // base cases
        // 1. empty string only has 1 way to decode
        if(s.length() == 0) return 1;
        // 2. invalid if string begin with 0
        if(s.charAt(0) == '0') return 0;
        // 3. one char string only has 1 way to decode
        if(s.length() == 1) return 1;
        // get count of decoding by first one char
        int count = count(s.substring(1));
        // get count of decoding by first two char
        if(s.length() >= 2
           && (s.charAt(0) < '3' && s.charAt(1) < '7' || s.charAt(0) < '2')){  // only test char from '10' to '26'
            count += count(s.substring(2));
        }
        // store checked result
        this.memo.put(s, count);
        return count;
    }
    /**
     * Given a non-empty string containing only digits, determine the total number of ways to decode it.
     * Characters are encoded like this way:
     * 'A' -> 1
     * 'B' -> 2
     * ...
     * 'Z' -> 26
     * @param s Given string
     * @return The total number of ways to decode the given string
     */
    public int numDecodings(String s) {
        // corner case
        if(s == null || s.length() == 0) return 0;
        memo = new HashMap<>();
        return this.count(s);
    }
}
// @lc code=end

// Improved Recursion solution
class Solution{

    // Use the begin index to record the current string
    HashMap<Integer, Integer> memo = new HashMap<>();
    /**
     * Get the number of ways to decode given String begin from given index
     * @param index Begin from given index
     * @param str Given string
     * @return int Number of ways
     */
    private int recursiveWithMemo(int index, String str) {

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str.charAt(index) == '0') {
            return 0;
        }

        if (index == str.length()-1) {
            return 1;
        }

        // Memoization is needed since we might encounter the same sub-string.
        if (memo.containsKey(index)) {
            return memo.get(index);
        }

        int ans = recursiveWithMemo(index+1, str);
        if (Integer.parseInt(str.substring(index, index+2)) <= 26) {
             ans += recursiveWithMemo(index+2, str);
         }

        // Save for memoization
        memo.put(index, ans);

        return ans;
    }
    /**
     * Given a non-empty string containing only digits, determine the total number of ways to decode it.
     * Characters are encoded like this way:
     * 'A' -> 1
     * 'B' -> 2
     * ...
     * 'Z' -> 26
     * @param s Given string
     * @return The total number of ways to decode the given string
     */
    public int numDecodings(String s) {
        // corner case
        if (s == null || s.length() == 0) {
            return 0;
        }
        return recursiveWithMemo(0, s);
    }
}


class Solution{
    /**
     * Given a non-empty string containing only digits, determine the total number of ways to decode it.
     * Characters are encoded like this way:
     * 'A' -> 1
     * 'B' -> 2
     * ...
     * 'Z' -> 26
     * @param s Given string
     * @return The total number of ways to decode the given string
     */
    public int numDecodings(String s) {
        // corner case
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s.charAt(0) == '0' ? 0 : 1;
        for(int i = 2; i < dp.length; ++i){
            // If the string starts with a zero, it can't be decoded
            // one char count
            if(s.charAt(i-1) != '0') {
               dp[i] += dp[i-1];  
            }
            // two char count
            int twoDigit = Integer.parseInt(s.substring(i - 2, i));
            if(twoDigit > 9 && twoDigit < 27){
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
}