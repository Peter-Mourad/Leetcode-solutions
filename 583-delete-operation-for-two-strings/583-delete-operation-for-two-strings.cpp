class Solution {
public:
    int dp[500][500];
    int solve(int i, int j, string &x, string &y){
        if(i==-1 || j==-1) return 0;
        int &ret = dp[i][j];
        if(~ret)return ret;
        if(x[i]==y[j]) return ret = 2 + solve(i - 1, j - 1, x, y);
        return ret = max(solve(i - 1, j, x, y), solve(i, j - 1, x, y));
    }
    int minDistance(string w1, string w2) {
        memset(dp,-1,sizeof dp);
        return w1.size() + w2.size() - solve(w1.size() - 1, w2.size() - 1, w1, w2);
    }
};