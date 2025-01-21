class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long> > pref(2, vector<long long> (n + 1));
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < n;j++){
                pref[i][j + 1] = pref[i][j] + grid[i][j];
            }
        }
        // see best index to move down
        long long ans = 1e18;
        for(int i = 0;i < n;i++){
            long long res = max(pref[0][n] - pref[0][i + 1], pref[1][i]);
            ans = min(ans, res);
        }
        return ans;
    }
};