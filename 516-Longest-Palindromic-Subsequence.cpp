class Solution {
public:
    int dp[1000][1000];
    int solve(int i, int j, string &x){
        if(i > j) return 0;
        if(i==j) return 1;
        if(~dp[i][j]) return dp[i][j];
        dp[i][j] = 0;
        if(x[i]==x[j])
            dp[i][j] = solve(i + 1, j - 1, x) + 2;
        return dp[i][j] = max({
            dp[i][j],
            solve(i + 1, j, x),
            solve(i, j - 1, x)
        });
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size() - 1, s);
    }
};