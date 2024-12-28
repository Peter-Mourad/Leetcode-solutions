class Solution {
public:
    int dp[20000][4];
    int solve(int i, int rem, int k, vector<int> &nums, vector<int> &pref){
        if(i==nums.size() || !rem) return 0;
        int &ret = dp[i][rem];
        if(~ret) return ret;
        int mn = min((int)nums.size(), i + k);
        return ret = max(solve(i + 1, rem, k, nums, pref), 
        solve(mn, rem - 1, k, nums, pref) + pref[mn] - pref[i]);
    }

    vector<int> ans;
    void trace(int i, int rem, int k, vector<int> &nums, vector<int> &pref){
        if(!rem) return;
        int mn = min((int)nums.size(), i + k);
        if(dp[i][rem]==solve(mn, rem - 1, k, nums, pref) + pref[mn] - pref[i]){
            ans.push_back(i);
            trace(mn, rem - 1, k, nums, pref);
        }
        else
            trace(i + 1, rem, k, nums, pref);
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n +1);
        for(int i = 0;i < n;i++){
            pref[i + 1] = pref[i] + nums[i];
        }
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 3, k, nums, pref);
        trace(0, 3, k, nums, pref);
        return ans;
    }
};