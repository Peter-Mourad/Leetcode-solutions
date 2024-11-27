class Solution {
public:
    void updateDistances(int s, vector<int>& dis, vector<vector<int>> &adj){
        int cur = dis[s] + 1;
        for(auto neighbour: adj[s]){
            if(dis[neighbour] <= cur) continue;
            dis[neighbour] = cur;
            updateDistances(neighbour, dis, adj);
        }
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dis(n);
        vector<vector<int>> adj(n);
        dis[0] = n - 1;
        for(int i = 1;i < n;i++){
            adj[i].push_back(i - 1);
            dis[i] = n - i - 1;
        }

        vector<int> ans(queries.size());
        for(int i = 0;i < queries.size(); i++){
            int s = queries[i][0], t = queries[i][1];
            adj[t].push_back(s);
            dis[s] = min(dis[s], dis[t] + 1);
            updateDistances(s, dis, adj);
            ans[i] = dis[0];
        }
        return ans;
    }
};