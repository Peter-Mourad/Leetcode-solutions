class Solution {
public:
    int dp[500][500];
    int solve(int i, int j, string &x, string &y){
        if(i==-1 || j==-1) return 0;
        if(~dp[i][j])return dp[i][j];
        if(x[i]==y[j]) return dp[i][j] = 2 + solve(i - 1, j - 1, x, y);
        return dp[i][j] = max(solve(i - 1, j, x, y), solve(i, j - 1, x, y));
    }
    int minDistance(string w1, string w2) {
        for(int i = 0;i < w1.size();i++){
            for(int j = 0;j < w2.size();j++)
                dp[i][j] = -1;
        }
        return w1.size() + w2.size() - solve(w1.size() - 1, w2.size() - 1, w1, w2);
    }
};