// @lc code=start
// bottom-top dp
// just convert the recursion solution
// Time: O(n^2)
// Space: O(n^2)
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int[][] dp = new int[arr.length][arr.length + 1];
        int[][] maxNum = new int[arr.length][arr.length + 1];
        for(int i = 0; i < arr.length; ++i){
            for(int j = i + 1; j < arr.length + 1; ++j){
                maxNum[i][j] = arr[j - 1] > maxNum[i][j - 1] ? arr[j - 1] : maxNum[i][j - 1];
            }
        }
        for(int i = arr.length - 1; i >= 0; --i){
            for(int j = i + 2; j < arr.length + 1; ++j){
                int cost = Integer.MAX_VALUE;
                for(int k = i + 1; k < j; k++){
                    cost = Math.min(cost, maxNum[i][k] * maxNum[k][j] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = cost;
            }    
        }
        return dp[0][arr.length];
    }
}
// @lc code=end
// Top-bottom recursion
class Solution {
    
    private HashMap<Integer, Integer> maxMemo;  // record computed max num
    private HashMap<Integer, Integer> costMemo;  // record computed cost
    /**
     * Get max number of array with range of [left, right)
     * @param arr Given array
     * @param left Start index
     * @param right End index
     * @return int Max number
     */
    private int maxNum(int[] arr, int left, int right){
        int key = left + 40 * right;
        if(this.maxMemo.containsKey(key)) return this.maxMemo.get(key);
        int value = 0;
        for(int i = left; i < right; ++i){
            if(arr[i] > value) value = arr[i];
        }
        this.maxMemo.put(key, value);
        return value;
    }
    /**
     * Recursively get min cost form given array with range of [left,right)
     * @param arr Given array
     * @param left Start index
     * @param right End index
     * @return Min cost
     */
    private int minCost(int[] arr, int left, int right){
        if(right - left < 2) return 0;
        int key = left + 40 * right;  // generate key simply
        if(this.costMemo.containsKey(key)) return this.costMemo.get(key);
        int cost = Integer.MAX_VALUE;
        // try split array in all possible position and compute min cost for each case
        for(int i = left + 1; i < right; i++){
            int left_max = maxNum(arr, left, i);
            int right_max = maxNum(arr, i, right);
            int left_cost = minCost(arr, left, i);
            int right_cost = minCost(arr, i, right);
            cost = Math.min(cost, left_max * right_max + left_cost + right_cost);
        }
        this.costMemo.put(key, cost);
        return cost;
    }
    public int mctFromLeafValues(int[] arr) {
        this.maxMemo = new HashMap<>();
        this.costMemo = new HashMap<>();
        return minCost(arr,0, arr.length);
    }
}