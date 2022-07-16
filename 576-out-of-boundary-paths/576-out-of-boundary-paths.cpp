#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    ll dp[52][52][51];
    ll solve(int i,int j,int rem, int &m, int &n){
        ll &ret = dp[i][j][rem];
        if(~ret)return ret;
        if(i==m + 1 || j==n + 1 || !i || !j)return ret = 1;
        if(!rem)return ret = 0;
        ret = 0;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            ret = (ret + solve(nx, ny, rem - 1, m, n)) % mod;
        }
        return ret;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i = 0;i <= m + 1;i++){
            for(int j = 0;j <= n + 1;j++){
                for(int k = 0;k <= maxMove;k++)
                    dp[i][j][k] = -1;
            }
        }
        return solve(startRow + 1, startColumn + 1, maxMove, m, n);
    }
};