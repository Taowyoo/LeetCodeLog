import java.util.HashMap;

/*
 * @lc app=leetcode id=139 lang=java
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (40.19%)
 * Likes:    5018
 * Dislikes: 250
 * Total Accepted:    606.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
    /**
     * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
     * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
     * @param s Given string
     * @param wordDict List of words
     * @return boolean Whether can be segmented
     */
    public boolean wordBreak(String s, List<String> wordDict) {
        // dp[x] means whether substring[0,x] of given string can be segmented
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for(int i = 0; i < dp.length; ++i){
            if(dp[i] == true){
                for(String word : wordDict){
                    if(i + word.length() < dp.length && s.startsWith(word,i)){
                        // if there is a word occur in dict
                            dp[i + word.length()] = true;
                    }
                }
            }
        }
        return dp[s.length()];
    }
}
// @lc code=end

class Solution {
    HashMap<String, Boolean> memo = new HashMap<>();  // record tried results
    /**
     * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
     * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
     * @param s Given string
     * @param wordDict List of words
     * @return boolean Whether can be segmented
     */
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s.length() == 0) {
            return true;
        }
        if(memo.containsKey(s))
            return memo.get(s);
        // check each word in the given string
        boolean ret = false;
        for(String word : wordDict){
            if(s.startsWith(word)){
                // remove current word and check recursively
                ret = wordBreak(s.substring(word.length()), wordDict);
                if(ret) break;
            }
        }
        memo.put(s,ret);
        return ret;
    }
}