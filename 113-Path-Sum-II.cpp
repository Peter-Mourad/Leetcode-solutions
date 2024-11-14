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
    vector<int> temp;
    void solve(TreeNode* cur, int sum, int target, vector<vector<int>> &ans){
        if(!cur) return;
        temp.push_back(cur->val);
        if(!cur->left && !cur->right){
            if(sum + cur->val==target)
                ans.push_back(temp);
        }
        solve(cur->left, sum + cur->val, target, ans);
        solve(cur->right,sum + cur->val, target, ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        solve(root, 0, targetSum, ans);
        return ans;
    }
};