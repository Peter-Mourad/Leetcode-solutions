class Solution {
public:
    int dp[201][201];
    int solve(int i, int cur, int &n, int &k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore){
        if(i==k)return 0;
        int &ret = dp[i][cur];
        if(~ret) return ret;
        ret = 0;
        for(int j = 0;j < n;j++){
            int res = solve(i + 1, j, n, k, stayScore, travelScore) + 
            ((cur==j) ? stayScore[i][j] : travelScore[cur][j]);
            ret = max(ret, res);
        }
        return ret;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0;i < n;i++)
            ans = max(ans, solve(0, i, n, k, stayScore, travelScore));
        return ans;
    }
};