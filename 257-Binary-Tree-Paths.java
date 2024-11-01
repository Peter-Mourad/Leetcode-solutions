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
    List<String> ans;
    void dfs(TreeNode root, String cur){
        if(root==null) return;
        if(cur != \\) cur += \->\;
        cur += String.valueOf(root.val);
        dfs(root.left, cur);
        dfs(root.right, cur);
        if(root.left==null && root.right==null)
            ans.add(cur);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        ans = new ArrayList<>();
        dfs(root, \\);
        return ans;
    }
}