class Solution {
public:
    int mod = 1e9 + 7;
    long long fast_power(long long n, long long pow){
        long long res = 1;
        while(pow){
            if(pow & 1)
                res = (res * n) % mod;
            n = (n * n) % mod;
            pow >>= 1;
        }
        return res;
    }

    int sum(long long a, long long b){
        return ((a % mod) + (b % mod)) % mod;
    }

    int mul(long long a, long long b){
        return ((a % mod) * (b % mod)) % mod;
    }

    int numberOfWays(int n, int x, int y) {
        int dp[n + 1][x + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= x; j++){
                dp[i][j] = sum(dp[i][j], mul(dp[i - 1][j], j));
                dp[i][j] = sum(dp[i][j], mul(dp[i - 1][j - 1], (x - j + 1)));
            }
        }

        long long ans = 0;
        for (int j = 1; j <= x; j++) 
            ans = sum(ans, mul(dp[n][j], fast_power(y, j)));

        return ans;
    }
};