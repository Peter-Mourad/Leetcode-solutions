class Solution {
public:
    int dp[100];
    int solve(int i, string &s){
        if(i >= s.size()) return 1;
        if(~dp[i])return dp[i];
        if(s[i]=='0') return dp[i] = 0;
        int res2 = 0;
        if(i + 1 < s.size() && 
        (s[i]=='1' || (s[i]=='2' && s[i + 1] < '7')))
            res2 = solve(i + 2, s);
        return dp[i] = solve(i + 1, s) + res2;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};