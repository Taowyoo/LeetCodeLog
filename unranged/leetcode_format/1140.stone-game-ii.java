import java.util.Arrays;
import java.util.HashMap;
import java.util.Objects;

/*
 * @lc app=leetcode id=1140 lang=java
 *
 * [1140] Stone Game II
 *
 * https://leetcode.com/problems/stone-game-ii/description/
 *
 * algorithms
 * Medium (63.71%)
 * Likes:    562
 * Dislikes: 133
 * Total Accepted:    19K
 * Total Submissions: 29.4K
 * Testcase Example:  '[2,7,9,4,4]'
 *
 * Alex and Lee continue their games with piles of stones.  There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].  The objective of the game is to end with the most
 * stones. 
 * 
 * Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * 
 * The game continues until all the stones have been taken.
 * 
 * Assuming Alex and Lee play optimally, return the maximum number of stones
 * Alex can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alex takes one pile at the beginning, Lee takes two piles,
 * then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total.
 * If Alex takes two piles at the beginning, then Lee can take all three piles
 * left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since
 * it's larger. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10 ^ 4
 * 
 * 
 */

// @lc code=start

class Solution {
    int[] piles;  // given stones number array
    int[] preSum;  // precomputed prefix sum for speeding up compute sum
    int[][] memo;  // record tried pick stone way

    int solve(int pilesBegin, int m){
        // if left piles number smaller than 2*m, take all the rest piles of stones
        if(pilesBegin + 2 * m >= this.piles.length){
            return preSum[piles.length] - preSum[pilesBegin];
        }
        // if visited return recorded value 
        if(memo[m][pilesBegin] > 0) return memo[m][pilesBegin];
        int res = 0;
        // try all possible way to take stones
        for(int x = 1; x <= 2*m; ++x){
            // get current number of picked stones
            int curPick = preSum[pilesBegin + x] - preSum[pilesBegin];
            // get the number of rest stones
            int rest = preSum[piles.length] - preSum[pilesBegin + x];
            // next time of number of picked stones is (rest - others picked number)
            int nextPick = rest - solve(pilesBegin + x, Math.max(m, x));
            // update max
            res = Math.max(res, curPick + nextPick);
        }
        memo[m][pilesBegin] = res;
        return res;
    }
    
    public int stoneGameII(int[] piles) {
        // corner case
        if(piles == null || piles.length == 0) return 0;

        this.piles = piles;
        // compute preSum to speed up subsequent computation
        preSum = new int[piles.length + 1];
        for(int i = 1; i <= piles.length; ++i){
            preSum[i] = preSum[i - 1] + piles[i - 1];
        }
        // memory to reduce extra recursive call
        this.memo = new int[piles.length][piles.length];
        return solve(0, 1);
    }
}
// @lc code=end

// test cases:
// '[2,7,9,4,4,2,7,9,4,4]'
