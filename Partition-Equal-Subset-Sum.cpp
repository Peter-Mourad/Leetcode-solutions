class Solution {
public:
    int dp[200][10001];
    bool solve(int i, int rem, vector<int>& nums){
        if(i==nums.size())
            return 0;
        if(!rem) return 1;
        int &ret = dp[i][rem];
        if(~ret) return ret;
        ret = 0;
        if(nums[i] <= rem)
            return ret = max(solve(i + 1,rem - nums[i], nums), solve(i + 1, rem, nums));
        return ret = 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums)
            sum+=num;
        if(sum & 1) return false;
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(), nums.end());
        return solve(0, sum / 2, nums);
    }
};