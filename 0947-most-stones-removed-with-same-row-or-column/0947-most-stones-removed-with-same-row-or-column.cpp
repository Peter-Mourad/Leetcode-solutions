class Solution {
public:
    set<vector<int> > s;
    map<vector<int>, bool> vis;
    
    void dfs(vector<int> cur){
        for(auto &v : s){
            if((v[0]==cur[0] || v[1]==cur[1]) && !vis[v]){
                vis[v] = 1;
                dfs(v);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0;i < stones.size();i++)
            s.insert(stones[i]);
        int ans = stones.size();
        while(!s.empty()){
            ans--;
            vector<int> cur = *s.begin();
            s.erase(cur);
            dfs(cur);
            for(auto v : vis)
                s.erase(v.first);
            vis.clear();
        }
        return ans;
    }
};