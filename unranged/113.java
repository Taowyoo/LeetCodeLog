// https://leetcode.com/problems/path-sum-ii/
// 113. Path Sum II

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
    /**
     * Node Structure for easy to create final lists from bottom to top
     */
    class Node{
        public int val;
        public Node parent;
        Node() {}
    }
    private List<List<Integer>> res;
    private int target;
    /**
     * Use current node and all its parent nodes to create one answer list
     * @param node Current leaf node
     */
    private void addAns(Node node){
        Node cur = node;
        List<Integer> list = new LinkedList<Integer>();
        while(cur != null){
            list.add(0,cur.val);
            cur = cur.parent;
        }
        res.add(list);
    }
    /**
     * Dfs all nodes to find valid node and construct a another tree with val and parent node
     * for final create answer list
     * @param root Current Node
     * @param curSum Sum of nodes' val so far
     * @param parentNode Parent node of current node
     */
    private void dfs(TreeNode root, int curSum ,Node parentNode){
        Node cur = new Node();
        cur.val = root.val;
        cur.parent = parentNode == null ? null : parentNode;
        curSum += root.val;
        if(root.left == null && root.right == null){
            if(curSum == target){
                addAns(cur);
            }
            return;
        }
        if(root.left != null){
            dfs(root.left,curSum,cur);
        }
        if(root.right != null){
            dfs(root.right,curSum,cur);
        }
        return;
    }
    /**
     * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
     * @param root The root node of given binary tree
     * @param sum Target sum
     * @return List<List<Integer>> Result list of path
     */
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        res = new ArrayList<List<Integer>>();
        if(root == null) return res;
        target = sum;
        dfs(root, 0 ,null);
        return res;
    }
}