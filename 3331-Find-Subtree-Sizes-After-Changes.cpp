class Solution {
public:
    map<char, vector<int> > charPositions;
    void dfs(int a, int par, string &s, vector<int> &ancestor, vector<vector<int>> &adj){
        if(!charPositions[s[a]].empty()) 
            ancestor[a] = charPositions[s[a]].back();
        charPositions[s[a]].push_back(a);
        for(auto &b: adj[a]){
            if(b==par)continue;
            dfs(b, a, s, ancestor, adj);
        }
        charPositions[s[a]].pop_back();
    }

    int dfs2(int a, int par, vector<int> &ans, vector<vector<int>> &adj){
        int res = 1;
        for(auto &b: adj[a]){
            if(b==par)continue;
            res += dfs2(b, a, ans, adj);
        }
        return ans[a] = res;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int> > adj(n);
        vector<int> ancestor = parent;
        for(int i = 1;i < n;i++)
            adj[parent[i]].push_back(i);
        dfs(0, -1, s, ancestor, adj);
        for(int i = 0;i < n;i++) adj[i].clear();
        for(int i = 1;i < n;i++) adj[ancestor[i]].push_back(i);

        vector<int> ans(n);
        dfs2(0, -1, ans, adj);
        return ans;
    }
};