class Solution {
public:
    int dp[100001], mod = 1e9 + 7;
    int add(long long a, long long b){
        return ((a % mod) + (b % mod)) % mod;
    }

    int solve(int n, int z, int o){
        if(~dp[n]) return dp[n];
        dp[n] = 1;
        if(n >= z) dp[n] = add(dp[n], solve(n - z, z, o));
        if(n >= o) dp[n] = add(dp[n], solve(n - o, z, o));
        return dp[n];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return (solve(high, zero, one) - solve(low - 1, zero, one) + mod) % mod;
    }
};