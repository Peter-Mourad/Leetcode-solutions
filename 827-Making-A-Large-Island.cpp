class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, n, m, id;
    int dfs(int i, int j, vector<vector<int> > &vis, vector<vector<int> > &grid){
        vis[i][j] = id;
        int sz = 1;
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny])
                sz += dfs(nx, ny, vis, grid);
        }
        return sz;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(), id = 1;
        vector<vector<int> > vis(n, vector<int> (m));
        vector<int> sz(n * m + 1);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j]) {
                    sz[id] = dfs(i, j, vis, grid);
                    id++;
                }
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!grid[i][j]){
                    set<int> islands;
                    for(int k = 0;k < 4;k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny])
                            islands.insert(vis[nx][ny]);
                    }
                    int res = 0;
                    for(auto i: islands)
                        res += sz[i];
                    ans = max(ans, res + 1);
                }
                else ans = max(ans, sz[vis[i][j]]);
            }
        }
        return ans;
    }
};