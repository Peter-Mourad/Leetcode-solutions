class Solution {
public:
    void parent_find(int a, int p, vector<int> &par, vector<vector<int> > &adj){
        for(auto b: adj[a]){
            if(b==p) continue;
            par[b] = a;
            parent_find(b, a, par, adj);
        }
    }

    int ans = INT_MIN;
    void dfs(int a, int p, int time, vector<int> &amount, vector<int> &vis, vector<vector<int> >&adj, int total){
        int res;
        if(~vis[a] && vis[a] <= time)
            res = (vis[a] < time ? 0 : amount[a] / 2);
        else 
            res = amount[a];
        for(auto b: adj[a]){
            if(b==p)continue;
            dfs(b, a, time + 1, amount, vis, adj, total + res);
        }
        if(adj[a].size()==1 && a)
            ans = max(ans, total + res);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        /*
            bob has only one path from bob node up to the root
            so the approach is to run dfs and mark nodes visited from bob
            and also the time so when running the dfs for alex i can know if 
            the current node gate is opened before or after bob opened it
        */

        int n = edges.size() + 1;
        vector<vector<int> > adj(n);
        for(auto edge: edges){
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> par(n);
        parent_find(0, -1, par, adj);
        vector<int> vis(n, -1);
        int cur = bob, time = 0;
        while(cur){
            vis[cur] = time++;
            cur = par[cur];
        }
        dfs(0, -1, 0, amount, vis, adj, 0);
        return ans;
    }
};