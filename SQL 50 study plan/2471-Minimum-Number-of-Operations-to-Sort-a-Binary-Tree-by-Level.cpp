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
    void dfs(TreeNode* cur, int level, vector<vector<int>> &lvl){
        if(!cur) return;
        if(level >= lvl.size()) lvl.push_back({});
        lvl[level].push_back(cur->val);
        dfs(cur->left, level + 1, lvl);
        dfs(cur->right, level + 1, lvl);
    }

    int minimumOperations(TreeNode* root) {
        // min no of swaps for each level = sum(cycle - 1) for all cycles
        vector<vector<int>> lvl;
        dfs(root, 0, lvl);

        int ans = 0;
        for(auto level: lvl){
            map<int, int> pos;
            vector<int> temp = level;
            sort(temp.begin(), temp.end());
            for(int i = 0;i < temp.size();i++){
                cout<<temp[i]<<' ';
                pos[temp[i]] = i;
            }
            cout<<endl;
            vector<int> vis(level.size());
            for(int i = 0;i < level.size();i++){
                if(vis[i] || i==pos[level[i]])continue;
                int cycle = 0, j = i;
                while(!vis[j]){
                    vis[j] = 1;
                    j = pos[level[j]];
                    cycle++;
                }
                ans += cycle - 1;
            }
        }
        return ans;
    }
};