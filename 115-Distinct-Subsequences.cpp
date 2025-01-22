class Solution {
public:
    int dp[1000][1000], n, m;
    int solve(int i, int j, string &s, string &t){
        if(n - i < m - j)return 0;
        if(i==n || j==m) return j==m;
        int &ret = dp[i][j];
        if(~ret) return ret;
        
        ret = 0;
        if(s[i]==t[j])
            ret = solve(i + 1, j + 1, s, t);
        return ret += solve(i + 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        n = s.size(), m = t.size();
        return solve(0, 0, s, t);
    }
};