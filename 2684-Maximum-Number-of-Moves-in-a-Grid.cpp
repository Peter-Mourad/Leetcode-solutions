class Solution {
public:
    int maxMoves(vector<vector<int>>& x) {
        int n = x.size(), m = x[0].size();
        vector<vector<int> > dp(n, vector<int> (m));
        for(int i = 0;i < n;i++) dp[i][0] = 1;
        int ans = 1;
        for(int j = 1;j < m;j++){
            for(int i = 0;i < n;i++){
                if(i && x[i][j] > x[i - 1][j - 1] && dp[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if(i + 1 < n && x[i][j] > x[i + 1][j - 1] && dp[i + 1][j - 1])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                if(x[i][j] > x[i][j - 1] && dp[i][j - 1])
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                    
                ans = max(ans, dp[i][j]);
            }
        }
        return ans - 1;
    }
};