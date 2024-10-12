class Solution {
public:
    pair<int,int> solve(TreeNode* root, int tot = 0){
        if(root==nullptr)
            return {-1e3,-1e3};
        int res = root->val;
        pair<int,int> left = solve(root->left, tot + res);
        pair<int,int> right = solve(root->right, tot + res);
        left.first = max(left.first,0);
        right.first = max(right.first,0);
        return {res + max(left.first,right.first), 
        max({left.second, right.second, 
        res + left.first + right.first})};
    }
    int maxPathSum(TreeNode* root) {
        return solve(root).second;
    }
};