class Solution {
public:
    vector<vector<int> > dp;
    int solve(int i, int rem, vector<int> &coins){
        if(!rem) return 1;
        if(i==coins.size() || (i < coins.size() && coins[i] > rem))
            return 0;
        int &ret = dp[i][rem];
        if(~ret) return ret;
        ret = 0;
        for(int x = 0;; x++){
            if(x * coins[i] > rem) break;
            ret += solve(i + 1, rem - x * coins[i], coins);
        }
        return ret;
    }
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>> (coins.size(), vector<int> (amount + 1, -1));
        sort(coins.begin(), coins.end());
        return solve(0, amount, coins);
    }
};