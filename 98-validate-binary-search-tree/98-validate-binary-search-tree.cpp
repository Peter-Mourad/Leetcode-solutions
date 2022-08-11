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
#define ll long long
class Solution {
public:
    bool validate(TreeNode* root,ll mn,ll mx){
        if(root->val < mn || root->val > mx)return false;
        bool ans = 1;
        ll mx2 = root->val,mn2 = root->val;
        if(root->left)
            ans &= validate(root->left,mn,mx2 - 1);
        if(root->right)
            ans &= validate(root->right,mn2 + 1,mx);
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,INT_MIN,INT_MAX);
    }
};