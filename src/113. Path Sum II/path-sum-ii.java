/*
 * File: path-sum-ii.java
 * File Created: 2021-01-15 12:44:48 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/path-sum-ii/
 * -----
 * Last Modified: 2021-01-15 13:21:11 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

// 113. Path Sum II
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


/**
 * My solution:
 * Create another tree(each node has pointer to its parent) while dfs
 * Time: O(n)
 * Space: O(n)
 * Let n be the size of given tree
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


/**
 * LeetCode solution
 * Depth First Traversal | Recursion
 */
class Solution {
    
    private void recurseTree(TreeNode node, int remainingSum, List<Integer> pathNodes, List<List<Integer>> pathsList) {
        
        if (node == null) {
            return;
        }
        
        // Add the current node to the path's list
        pathNodes.add(node.val);
        
        // Check if the current node is a leaf and also, if it
        // equals our remaining sum. If it does, we add the path to
        // our list of paths
        if (remainingSum == node.val && node.left == null && node.right == null) {
            pathsList.add(new ArrayList<>(pathNodes));
        } else {
            
            // Else, we will recurse on the left and the right children
            this.recurseTree(node.left, remainingSum - node.val, pathNodes, pathsList);
            this.recurseTree(node.right, remainingSum - node.val, pathNodes, pathsList);
        }
        
        // We need to pop the node once we are done processing ALL of it's
        // subtrees.
        pathNodes.remove(pathNodes.size() - 1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> pathsList = new ArrayList<List<Integer>>();
        List<Integer> pathNodes = new ArrayList<Integer>();
        this.recurseTree(root, sum, pathNodes, pathsList);
        return pathsList;        
    }
}