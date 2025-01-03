class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int j = 0;j < m;j++){
            for(int i = 1;i < n;i++){
                ans += max(0, grid[i - 1][j] - grid[i][j] + 1);
                grid[i][j] = max(grid[i][j], grid[i - 1][j] + 1);
            }
        }
        return ans;
    }
};