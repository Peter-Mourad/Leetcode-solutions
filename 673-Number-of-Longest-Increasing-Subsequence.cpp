class Solution {
public:
    int dp[2000][2001], cnt[2000][2001];
    int solve(int i, int prev, vector<int> &nums){
        if(i==nums.size()) return 0;
        int &ret = dp[i][prev];
        if(~ret) return ret;

        if(prev==2000)
            return ret = max(solve(i + 1, i, nums) + 1, solve(i + 1, prev, nums));
            
        if(nums[i] > nums[prev])
            ret = solve(i + 1, i, nums) + 1;
        return ret = max(solve(i + 1, prev, nums), ret);
    }

    int trace(int i, int prev, vector<int> &nums){
        if(i==nums.size()) return 1;
        int &ret = dp[i][prev];
        int &ret2 = cnt[i][prev];
        if(~ret2) return ret2;
        ret2 = 0;
        if(ret == solve(i + 1, i, nums) + 1)
            ret2 += trace(i + 1, i, nums);

        if(ret == solve(i + 1, prev, nums))
            ret2 += trace(i + 1, prev, nums);
        return ret2;
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        memset(cnt, -1, sizeof(cnt));
        solve(0, 2000, nums);
        return trace(0, 2000, nums);
    }
};