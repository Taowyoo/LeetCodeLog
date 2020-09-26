/*
 * @lc app=leetcode id=464 lang=java
 *
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (28.85%)
 * Likes:    1066
 * Dislikes: 181
 * Total Accepted:    54.8K
 * Total Submissions: 186.9K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game" two players take turns adding, to a running total, any
 * integer from 1 to 10. The player who first causes the running total to reach
 * or exceed 100 wins.
 * 
 * What if we change the game so that players cannot re-use integers?
 * 
 * For example, two players might take turns drawing from a common pool of
 * numbers from 1 to 15 without replacement until they reach a total >= 100.
 * 
 * Given two integers maxChoosableInteger and desiredTotal, return true if the
 * first player to move can force a win, otherwise return false. Assume both
 * players play optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: maxChoosableInteger = 10, desiredTotal = 11
 * Output: false
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: maxChoosableInteger = 10, desiredTotal = 0
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: maxChoosableInteger = 10, desiredTotal = 1
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= maxChoosableInteger <= 20
 * 0 <= desiredTotal <= 300
 * 
 * 
 */

// @lc code=start
public class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal<=0) return true;
        if (maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal) return false;
        return canIWin(desiredTotal, new int[maxChoosableInteger], new HashMap<>());
    }
    private boolean canIWin(int total, int[] state, HashMap<String, Boolean> hashMap) {
        String curr=Arrays.toString(state);
        if (hashMap.containsKey(curr)) return hashMap.get(curr);
        for (int i=0;i<state.length;i++) {
            if (state[i]==0) {
                state[i]=1;
                if (total<=i+1 || !canIWin(total-(i+1), state, hashMap)) {
                    hashMap.put(curr, true);
                    state[i]=0;
                    return true;
                }
                state[i]=0;
            }
        }
        hashMap.put(curr, false);
        return false;
    }
}
// @lc code=end

