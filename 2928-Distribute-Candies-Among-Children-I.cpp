class Solution {
public:
    int dp[3][51];
    int solve(int i, int rem, int &limit){
        if(i==3) return !rem;
        int &ret = dp[i][rem];
        if(~ret) return ret;
        ret = 0;
        for(int c = 0;c <= min(rem, limit);c++){
            ret += solve(i + 1, rem - c, limit);
        }
        return ret;
    }
    int distributeCandies(int n, int limit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, limit);
    }
};