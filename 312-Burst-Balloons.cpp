class Solution {
public:
    int solve(int i, int j, vector<vector<int> > &dp, vector<int> &nums){
        if(i > j) return 0;

        int &ret = dp[i][j];
        if(~ret) return ret;

        ret = 0;
        for(int k = i; k <= j; k++){
            int res = (
                (nums[i - 1] * nums[k] * nums[j + 1]) + 
                solve(i, k - 1, dp, nums) + 
                solve(k + 1, j, dp, nums)
            );
            ret = max(ret, res);
        }

        return ret;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));

        return solve(1, n, dp, nums);
    }
};