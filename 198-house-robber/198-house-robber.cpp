class Solution {
public:
    int dp[100],n;
    int solve(int i,vector<int>& x){
        if(i>=n)return 0;
        int &ret = dp[i];
        if(~ret)return ret;
        return ret = max(solve(i + 2,x) + x[i],solve(i + 1,x));
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof dp);
        return solve(0,nums);
    }
};