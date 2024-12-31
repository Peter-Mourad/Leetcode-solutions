class Solution {
public:
    int dp[367];
    int solve(int i, vector<int>& days, vector<int>& costs){
        if(i > days.back()) return 0;
        int temp = lower_bound(days.begin(), days.end(), i) - days.begin();
        i = days[temp];
        if(~dp[i])return dp[i];
        dp[i] = INT_MAX;
        for(int j = 0;j < 3;j++){
            int d = 1;
            if(j==1) d = 7;
            else if(j==2) d = 30;
            for(int f = 1; ;f++){
                dp[i]= min(dp[i], solve(i + f * d, days, costs) + f * costs[j]);
                if(f * d + i > 365)break;
            }
        }
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(days[0], days, costs);
    }
};