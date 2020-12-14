import java.util.HashMap;

/*
 * @lc app=leetcode id=1130 lang=java
 *
 * [1130] Minimum Cost Tree From Leaf Values
 *
 * https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
 *
 * algorithms
 * Medium (66.16%)
 * Likes:    1441
 * Dislikes: 115
 * Total Accepted:    38.7K
 * Total Submissions: 57.8K
 * Testcase Example:  '[6,2,4]'
 *
 * Given an array arr of positive integers, consider all binary trees such
 * that:
 * 
 * 
 * Each node has either 0 or 2 children;
 * The values of arr correspond to the values of each leaf in an in-order
 * traversal of the tree.  (Recall that a node is a leaf if and only if it has
 * 0 children.)
 * The value of each non-leaf node is equal to the product of the largest leaf
 * value in its left and right subtree respectively.
 * 
 * 
 * Among all possible binary trees considered, return the smallest possible sum
 * of the values of each non-leaf node.  It is guaranteed this sum fits into a
 * 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [6,2,4]
 * Output: 32
 * Explanation:
 * There are two possible trees.  The first has non-leaf node sum 36, and the
 * second has non-leaf node sum 32.
 * 
 * ⁠   24            24
 * ⁠  /  \          /  \
 * ⁠ 12   4        6    8
 * ⁠/  \               / \
 * 6    2             2   4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 40
 * 1 <= arr[i] <= 15
 * It is guaranteed that the answer fits into a 32-bit signed integer (ie. it
 * is less than 2^31).
 * 
 */

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