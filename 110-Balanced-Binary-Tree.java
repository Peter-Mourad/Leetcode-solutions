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
    boolean ans = true;
    int checkTreeBalanced(TreeNode root){
        if(root==null)return 0;
        int left = checkTreeBalanced(root.left);
        int right = checkTreeBalanced(root.right);
        ans &= Math.abs(left - right) < 2;
        return Math.max(left, right) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        checkTreeBalanced(root);
        return ans;
    }
}