class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* t){
        if(t==nullptr)return 1;
        
        int left = dfs(t->left);
        int right = dfs(t->right);
        
        if(left==-1 || right==-1){
            ans++;
            return 0;
        }
        else if(!left || !right) 
            return 1;
        else
            return -1;
    }
    int minCameraCover(TreeNode* root) {
        int res = dfs(root);
        return ans + (~res ? 0 : 1);
    }
};