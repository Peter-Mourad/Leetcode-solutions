class Solution {
public:
    pair<int,int> ans = {0,1e9};
    vector<vector<pair<int,int> > > adj;
    vector<int> vis, pref;
    void dfs(int i, int u, int par, int l, vector<int> &nums){
        int vis_id = vis[nums[u]];
        if(~vis_id && vis_id >= l)
            l = vis_id + 1;
        vis[nums[u]] = i;
        for(auto [v, len]: adj[u]){
            if(v == par) continue;
            pref[i + 1] = pref[i] + len;
            dfs(i + 1, v, u, l, nums);
        }
        int len = pref[i] - pref[l];
        if(len > ans.first)
            ans = {len, i - l + 1};
        else if(len == ans.first)
            ans.second = min(ans.second, i - l + 1);
        vis[nums[u]] = vis_id;
    }
    
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        adj.resize(50003);
        vis = vector<int> (50003, -1);
        pref.resize(50003);
        for(auto p: edges){
            adj[p[0]].emplace_back(p[1], p[2]);
            adj[p[1]].emplace_back(p[0], p[2]);
        }
        dfs(0, 0, -1, 0, nums);
        return {ans.first, ans.second};
    }
};