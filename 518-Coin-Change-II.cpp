class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++){
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};