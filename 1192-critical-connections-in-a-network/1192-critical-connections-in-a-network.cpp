class Solution {
public:
    
vector<int> adj[100000],vis,Time,low,par,temp;
vector<vector<int>> ans;
int t;
void construct(int n){
    vis = vector<int> (n);
    Time = vector<int> (n);
    low = vector<int> (n);
    par = vector<int> (n);
    t = 0;
}
void dfs(int u){
    vis[u] = 1;
    Time[u] = low[u] = ++t;
    for(auto v : adj[u]){
        if(!vis[v]){
            par[v] = u;
            dfs(v);
            low[u]  = min(low[u], low[v]);
            if (low[v] > Time[u]){
                temp.clear();
                temp.push_back(u);
                temp.push_back(v);
                ans.push_back(temp);
            }
        }
        else if (v != par[u])
            low[u]  = min(low[u], Time[v]);
    }
}
    vector<vector<int>> criticalConnections(int n,          vector<vector<int>>& connections) {
        construct(n);
        for(auto p : connections){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        for(int i = 0;i < n;i++){
            if(!vis[i])dfs(i);
        }
        return ans;
    }
};