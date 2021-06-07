class Solution {
    /**
     * Get max money could rob in one night without rob adjacent houses
     * @param nums List of money in houses
     * @return int Max money
     */
    public int rob(int[] nums) {
        // corner case
        if(nums == null || nums.length == 0) return 0;
        // let dp[x] be the max money can rob in first x houses;
        // dp[x] = max(dp[x - 1], dp[x - 2] + money[x]) 
        int []dp = new int[nums.length + 1];
        // no house no money
        dp[0] = 0;
        // one house only one choice
        dp[1] = nums[0];
        for(int x = 2; x <= nums.length; x++){
            // choose max money from rob adjacent or rob with 1 interval
            dp[x] = Math.max(dp[x - 1], dp[x - 2] + nums[x - 1]);
        }
        return dp[nums.length];
    }
}