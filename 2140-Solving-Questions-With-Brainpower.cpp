class Solution {
public:
    long long dp[100000], n;
    long long solve(int i, vector<vector<int>> &q){
        if(i >= n) return 0;
        if(~dp[i]) return dp[i];
        return dp[i] = max(solve(i + 1, q), solve(i + q[i][1] + 1, q) + q[i][0]);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, questions);
    }
};