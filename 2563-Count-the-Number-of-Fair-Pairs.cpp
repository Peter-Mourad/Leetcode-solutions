class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0;i < nums.size();i++){
            int left = lower - nums[i], right = upper - nums[i];
            int l = lower_bound(nums.begin(), nums.end(), left) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), right) - nums.begin() - 1;
            if(l <= r) ans += r - l + !(nums[i] * 2 >= lower && nums[i] * 2 <= upper);
        }
        return ans / 2;
    }
};