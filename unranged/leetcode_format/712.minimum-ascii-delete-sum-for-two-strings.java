import java.util.HashMap;

/*
 * @lc app=leetcode id=712 lang=java
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (58.57%)
 * Likes:    1050
 * Dislikes: 49
 * Total Accepted:    38.2K
 * Total Submissions: 65.1K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */

// @lc code=start
// bottom-top dp
// just convert the recursion solution
// Time: O(n^2)
// Space: O(n^2)
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        
        for(int i = 1; i <= s2.length(); ++i){
            dp[0][i] = dp[0][i - 1] + s2.charAt(i - 1);
        }
        for(int i = 1; i <= s1.length(); ++i){
            dp[i][0] = dp[i - 1][0] + s1.charAt(i - 1);
        }
        for(int i = 1; i <= s1.length(); ++i){
            for(int j = 1; j <= s2.length(); ++j){
                if(s1.charAt(i - 1) == s2.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    int s1_num = dp[i - 1][j] + s1.charAt(i - 1);
                    int s2_num = dp[i][j - 1] + s2.charAt(j - 1);
                    dp[i][j] = Math.min(s1_num, s2_num);
                }
            }
        }
        

        return dp[s1.length()][s2.length()];
    }
    
}
// @lc code=end

// Top-bottom recursion
class Solution {
    private HashMap<Integer, Integer> memo; // record test cases
    public int minimumDeleteSum(String s1, String s2) {
        memo = new HashMap<>();
        return process(s1,s2,0,0);
    }
    /**
     * Check two string traverse with two pointer recursively
     * @param s1 Given string 1
     * @param s2 Given string 2
     * @param x1 Begin index of string 1
     * @param x2 Begin index of string 2
     * @return int The minimum ascii delete sum
     */
    private int process(String s1, String s2, int x1, int x2){
        int ans = 0;
        // as two index max to 1000, generate key simply
        int key = x1 * 1000 + x2;
        // if checked, use recorded value
        if(this.memo.containsKey(key)) return this.memo.get(key);
        // if reach end of string 1, add all rest of string 2
        if(x1 == s1.length()){
            for(int i = x2; i < s2.length(); i++){
                ans += s2.charAt(i);
            }
            return ans;
        }
        // if reach end of string 2, add all rest of string 1
        else if(x2 == s2.length()){
            for(int i = x1; i < s1.length(); i++){
                ans += s1.charAt(i);
            }
            return ans;
        }
        // if current place two char match, no need to delete, process next char
        else if(s1.charAt(x1) == s2.charAt(x2)){
            ans = process(s1, s2, x1 + 1, x2 + 1);
        }
        // recursively process and use the smaller one
        else{
            ans = Math.min(process(s1, s2, x1, x2 + 1) + s2.charAt(x2),
                            process(s1, s2, x1 + 1, x2) + s1.charAt(x1));
        }
        this.memo.put(key, ans);
        return ans;
    }
}
