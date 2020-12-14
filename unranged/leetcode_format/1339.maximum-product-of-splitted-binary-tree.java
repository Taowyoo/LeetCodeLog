import java.util.ArrayList;

/*
 * @lc app=leetcode id=1339 lang=java
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    346
 * Dislikes: 33
 * Total Accepted:    17.9K
 * Total Submissions: 48K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a binary tree root. Split the binary tree into two subtrees by
 * removing 1 edge such that the product of the sums of the subtrees are
 * maximized.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation:  Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,3,9,10,7,8,6,5,4,11,1]
 * Output: 1025
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * Each tree has at most 50000 nodes and at least 2 nodes.
 * Each node's value is between [1, 10000].
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static final long mod = 1000000007;
    ArrayList<Integer> count;
    /**
     * Recursively compute max sum from subtrees
     * @param root Current tree root
     * @return Max Sum
     */
    int computeSum(TreeNode root){
        if(root == null) return 0;
        // Max sum of current tree equals sum of subtrees' sum and current node value
        int e = computeSum(root.left) + computeSum(root.right) + root.val;
        // save current tree sum to a list
        count.add(e);
        return e;
    }
    /**
     * Got all max sum then compute max product
     * @param root Tree root
     * @return int Max product
     */
    public int maxProduct(TreeNode root) {
        count = new ArrayList<>();
        int sum = computeSum(root);
        // find two number those are neatest to rootSum/2
        int minDis = Integer.MAX_VALUE;
        int nearest = 0;
        for(int i : count){
            int dis = Math.abs(sum - i * 2);
            if (dis < minDis) {
                minDis = dis;
                nearest = i;
            }
        }
        // compute result
        long ans =  ((long)sum - (long)nearest) * (long)nearest;
        return (int)((ans) % mod);
    }
}
// @lc code=end

