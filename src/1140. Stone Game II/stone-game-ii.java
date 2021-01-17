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