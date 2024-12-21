class Solution {
public:
    pair<long long, int> dfs(int i, int par, vector<vector<int>> &adj, vector<int> &val, int &k){
        long long sum = val[i], res = 0;
        for(auto j: adj[i]){
            if(j==par) continue;
            auto p = dfs(j, i, adj, val, k);
            sum += p.first, res += p.second;
        }
        if(sum % k==0)
            sum = 0, res++;
        return make_pair(sum, res);
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int> > adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, adj, values, k).second;
    }
};