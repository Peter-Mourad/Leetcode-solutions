/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode *a, int lvl  = 0){
        if(!a) return;
        if(lvl >= ans.size()) ans.push_back(INT_MIN);
        ans[lvl] = max(a->val, ans[lvl]);
        dfs(a->left, lvl + 1);
        dfs(a->right, lvl + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root);
        return ans;
    }
};