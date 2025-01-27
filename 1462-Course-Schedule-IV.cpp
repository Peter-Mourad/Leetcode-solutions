class Solution {
public:
    void dfs(int u, int s, vector<int> &vis, vector<vector<int>> &adj, vector<vector<int>> &isPre){
        vis[u] = 1;
        isPre[s][u] = 1;
        for(auto v: adj[u]){
            if(vis[v])continue;
            dfs(v, s, vis, adj, isPre);
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int> > adj(n);
        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        vector<int> vis(n);
        vector<vector<int>> isPre(n, vector<int> (n));
        for(int i = 0;i < n;i++){
            dfs(i, i, vis, adj, isPre);
            vis = vector<int> (n);
        }
        vector<bool> ans(queries.size());
        for(int i = 0;i < queries.size(); i++){
            ans[i] = isPre[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};