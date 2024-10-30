class Solution {
public:
    int dp[1000][1000][2];
    int solve(int i, int prev, bool dir, vector<int> &nums){
        if(i==-1 || i==nums.size())return 0;
        int &ret = dp[i][prev][dir];
        if(~ret) return ret;

        int next = i + (!dir ? -1 : 1);
        int res1 = (nums[i] < nums[prev] ? solve(next, i, dir, nums) + 1 : 0);
        int res2 = solve(next, prev, dir, nums);

        return ret = max(res1, res2);
    }

    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size(),ans = 0;
        for(int i = 0;i < n;i++){
            int res1 = solve(i - 1, i, 0, nums), res2 = solve(i + 1, i, 1, nums);
            if(res1 && res2)
                ans = max(ans, res1 + res2 + 1);
        }
        return n - ans;
    }
};