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