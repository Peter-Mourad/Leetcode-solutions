class Solution {
public:
    vector<int> ans;
    void dfs(int u, int p, vector<int> &par, vector<int> &vis, vector<vector<int>> &adj, map<pair<int,int>, int> &order){
        vis[u] = 1, par[u] = p;
        for(auto v: adj[u]){
            if(!ans.empty())return;
            if(v==p) continue;
            if(vis[v]){ // cycle found
                int last = u, mx = order[{u, v}];
                ans = {u,v};
                while(par[last] != v && par[last] != -1){
                    if(order[{last, par[last]}] > mx){
                        mx = order[{last, par[last]}];
                        ans = {last, par[last]};
                    }
                    last = par[last];
                }
                return;
            }
            else
                dfs(v, u, par, vis, adj, order);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        map<pair<int,int>, int> order;
        for(int i = 0;i < edges.size();i++){
            auto edge = edges[i];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            order[{edge[0], edge[1]}] = i;
            order[{edge[1], edge[0]}] = i;
        }
        vector<int> par(n + 1), vis(n + 1);
        dfs(1, -1, par, vis, adj, order);
        for(auto edge: edges){
            if((ans[0]==edge[1] && ans[1]==edge[0]) || ans==edge)
                return edge;
        }
        return {};
    }
};