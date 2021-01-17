/**
 * A bottom-top dp solution
 * Time complexity: O(mn), n = coins.length and m = amount
 * Space complexity: O(m)
 */
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

/**
 * A top-bottom dp solution with memory to speed up
 */

public class Solution {

    public int coinChange(int[] coins, int amount) {
      if (amount < 1) return 0;
      return coinChange(coins, amount, new int[amount]);
    }
    /**
     * Solution function
     * @param coins Coins array
     * @param rem Remaining amount
     * @param count Memory arr for counts of different amount
     * @return Result number of coins for given amount(rem)
     */
    private int coinChange(int[] coins, int rem, int[] count) {
      if (rem < 0) return -1;
      if (rem == 0) return 0;
      if (count[rem - 1] != 0) return count[rem - 1];
      int min = Integer.MAX_VALUE;
      for (int coin : coins) {
        int res = coinChange(coins, rem - coin, count);
        if (res >= 0 && res < min)
          min = 1 + res;
      }
      count[rem - 1] = (min == Integer.MAX_VALUE) ? -1 : min;
      return count[rem - 1];
    }
  }