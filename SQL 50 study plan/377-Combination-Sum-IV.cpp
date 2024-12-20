class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<__int128> dp(target + 1) ;
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto a : nums){
                if(i >= a)
                    dp[i] += dp[i - a];
            }
        }
        return dp[target];
    }
};