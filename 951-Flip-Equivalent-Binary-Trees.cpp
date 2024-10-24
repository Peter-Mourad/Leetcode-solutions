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
    bool dfs(TreeNode* cur1, TreeNode* cur2){
        if(!cur1 && !cur2) return true;
        if(!cur1 || !cur2 || cur1->val != cur2->val) return false;
        int children1 = (cur1->left ? 1 : 0) + (cur1->right ? 1 : 0)
        , children2 = (cur2->left ? 1 : 0) + (cur2->right ? 1 : 0);
        if(children1!=children2) return false;
        if((cur1->left && !cur2->left) || (cur1->right && !cur2->right)
        || (children1==2 && cur1->left->val != cur2->left->val))
            swap(cur1->left, cur1->right);
        bool res = dfs(cur1->left, cur2->left);
        return res & dfs(cur1->right, cur2->right);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};