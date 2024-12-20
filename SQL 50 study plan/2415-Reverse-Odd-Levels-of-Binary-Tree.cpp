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
    void dfs(TreeNode* cur, int lvl, vector<vector<int>> &level){
        if(!cur) return;
        if(lvl / 2 <= lvl && lvl) level.push_back({});
        if(lvl & 1)
            level[lvl / 2].push_back(cur->val);
        dfs(cur->left, lvl + 1, level);
        dfs(cur->right, lvl + 1, level);
    }

    void assign(TreeNode* cur, int lvl, vector<vector<int>> &level, vector<int> &curIndex){
        if(!cur) return;
        if(lvl & 1)
            cur->val = level[lvl / 2][curIndex[lvl / 2]++];
        assign(cur->left, lvl + 1, level, curIndex);
        assign(cur->right, lvl + 1, level, curIndex);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> level;
        dfs(root, 0, level);
        for(auto &lvl: level)
            reverse(lvl.begin(), lvl.end());
        vector<int> curIndex(level.size());
        assign(root, 0, level, curIndex);
        return root;
    }
};