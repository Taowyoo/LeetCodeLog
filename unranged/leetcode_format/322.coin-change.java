/*
 * @lc app=leetcode id=322 lang=java
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (35.64%)
 * Likes:    4945
 * Dislikes: 150
 * Total Accepted:    469.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: coins = [1], amount = 1
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: coins = [1], amount = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
    /**
     * Give coins of different denominations and coins can be used multiple times.
     * Compute the fewest number of coins that you need to make up given amount.
     * @param coins The list of coins of different denominations
     * @param amount Target amount
     * @return int The fewest number of coins we need to use
     */
    public int coinChange(int[] coins, int amount) {
        // corner case
        // no coin need to reach 0
        if(amount == 0) return 0;
        // invalid input
        if(coins == null || coins.length == 0) return -1;
        // dp array
        // dp[x] means to reach amount x, the fewest number of coins we need to use
        int[] dp = new int[amount + 1];
        // fill with big value to help following compare
        Arrays.fill(dp, Integer.MAX_VALUE);
        // no coin need to reach 0
        dp[0] = 0;
        // Traverse all amount from 1 to given amount:
        // Update: dp[x] = min{dp[x - coin[i]] + 1 | i = [0,coins.length)}
        // Means, try each coins, and our mission compose to dp[x - coinValue]
        // So we choose the smallest one then add 1 (current selected coin)
        for(int i = 1; i <= amount ; i++){
            int minLast = Integer.MAX_VALUE;
            for(int coin : coins){
                if(i - coin >= 0)
                    minLast = Math.min(minLast, dp[i - coin]);
            }
            if(minLast != Integer.MAX_VALUE)
                dp[i] = minLast + 1;
        }
        // After traverse return the number for target amount
        // Also check whether it has been updated, if not:
        // It means we can not make up given amount with given coins
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}
// @lc code=end

