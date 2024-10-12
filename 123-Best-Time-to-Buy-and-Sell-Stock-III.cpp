class Solution {
public:
    int dp[100000][3][2]; // state i, have stock
    int solve(int i, int rem, bool have, vector<int>& prices){
        if(i==prices.size())
            return 0;
        int &ret = dp[i][rem][have];
        if(~ret) return ret;
        ret = 0;
        if(have)
            ret = solve(i + 1, rem, 0, prices) + prices[i];
        else if(rem)
            ret = solve(i + 1, rem - 1, 1, prices) - prices[i];
        return ret = max(ret, solve(i + 1, rem, have, prices));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0, 2, 0, prices);
    }
};