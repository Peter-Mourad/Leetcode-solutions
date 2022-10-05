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
    void dfs(TreeNode* cur, int depth, int& need_depth, int& val){
        if(depth==need_depth){
            TreeNode* new_node = new TreeNode(val);
            TreeNode* temp = cur->left;
            cur->left = new_node;
            if(cur->left!=nullptr)
                new_node->left = temp;
            
            temp = cur->right;
            new_node = new TreeNode(val);
            cur->right = new_node;
            if(cur->right!=nullptr)
                new_node->right = temp;
            
            return;
        }
        if(cur->left)
            dfs(cur->left, depth + 1, need_depth, val);
        if(cur->right)
            dfs(cur->right, depth + 1, need_depth, val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* new_root = new TreeNode(val);
            if(root != nullptr)
                new_root->left = root;
            return new_root;
        }
        dfs(root, 1, --depth, val);
        return root;
    }
};