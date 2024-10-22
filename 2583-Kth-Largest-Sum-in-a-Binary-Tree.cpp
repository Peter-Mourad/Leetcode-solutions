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
    vector<long long> levelSum;
    void dfs(TreeNode* root, int level){
        if(!root)return;
        if(level >= levelSum.size()) levelSum.push_back(0);
        levelSum[level] += root->val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        if(levelSum.size() < k)return -1;
        sort(levelSum.rbegin(), levelSum.rend());
        return levelSum[k - 1];
    }
};