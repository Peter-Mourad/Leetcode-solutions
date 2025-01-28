class Solution {
public:
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    int n,m;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int res = grid[i][j];
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny])
                res += dfs(nx,ny,grid,vis);
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int> > vis(n, vector<int> (m));
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!grid[i][j]) continue;
                ans = max(ans, dfs(i, j, grid, vis));
            }
        }
        return ans;
    }
};