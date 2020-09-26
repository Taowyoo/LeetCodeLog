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
class Solution {
    private HashMap<String, Integer> memo;
    private int count(String s){
        
        if(memo.containsKey(s)){
            return memo.get(s);
        }
        if(s.length() == 0) return 1;
        if(s.charAt(0) == '0') return 0;
        if(s.length() == 1) return 1;
        int count = count(s.substring(1));
        if(s.length() >= 2
           && (s.charAt(0) < '3' && s.charAt(1) < '7' || s.charAt(0) < '2')){
            count += count(s.substring(2));
        }
        this.memo.put(s, count);
        return count;
    }
    public int numDecodings(String s) {
        if(s == null || s.length() == 0) return 0;
        memo = new HashMap<>();
        return this.count(s);
    }
}
// @lc code=end

class Solution{

    HashMap<Integer, Integer> memo = new HashMap<>();

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
    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        return recursiveWithMemo(0, s);
    }
}