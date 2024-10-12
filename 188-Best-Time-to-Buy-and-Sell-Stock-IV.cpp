class Solution {
public:
    int dp[1000][101][2]; // state i, rem k, have stock
    int solve(int i, int rem, bool have, vector<int>& prices){
        if(i==prices.size())
            return 0;
        int &ret = dp[i][rem][have];
        if(~ret) return ret;
        ret = 0;
        // if i have stock i can sell
        // else i can buy stock
        // i can do nothing
        if(have){
            ret = solve(i + 1, rem, 0, prices) + prices[i];
        }
        else if(rem){
            ret = solve(i + 1, rem - 1, 1, prices) - prices[i];
        }
        else return ret;
        return ret = max(ret, solve(i + 1, rem, have, prices));
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0, k, 0, prices);
    }
};