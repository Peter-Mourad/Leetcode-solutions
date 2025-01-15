class Solution {
public:
    int dp[1000][1000];
    int solve(int i, int j, string &s1, string &s2){
        if(i==s1.size() && j==s2.size())return 0;
        int res = 0;
        if(i==s1.size()){
            while(j < s2.size())
                res += s2[j++];
            return res;
        }
        if(j==s2.size()){
            while(i < s1.size())
                res += s1[i++];
            return res;
        }
        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = 0;
        if(s1[i]==s2[j])
            return ret = solve(i + 1, j + 1, s1, s2);
        return ret = min(
            solve(i + 1, j, s1, s2) + s1[i], 
            solve(i, j + 1, s1, s2) + s2[j]
        );
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2);
    }
};