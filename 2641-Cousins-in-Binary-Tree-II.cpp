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
    void dfs(TreeNode* cur, int level, vector<int> &lvlSum){
        if(!cur) return;
        if(lvlSum.size() <= level) lvlSum.push_back(0);
        lvlSum[level] += cur->val;
        if(cur->left)
            dfs(cur->left, level + 1, lvlSum);
        if(cur->right)
            dfs(cur->right, level + 1, lvlSum);
    }

    void modifiedTree(TreeNode* root, int sum, int lvl, vector<int> &lvlSum){
        if(!root) return;
        int childrenSum = (root->right ? root->right->val : 0)
        + (root->left ? root->left->val : 0);
        root->val = lvlSum[lvl] - sum;
        if(root->left)
            modifiedTree(root->left, childrenSum, lvl + 1, lvlSum);
        if(root->right)
            modifiedTree(root->right, childrenSum, lvl + 1, lvlSum);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> lvlSum;
        dfs(root, 0, lvlSum);
        modifiedTree(root, root->val, 0, lvlSum);
        return root;
    }
};