class Solution {
public:
    int solve(int i, int sum, vector<int> &nums, const int &target){
        if(i==nums.size())
            return sum == target;
        return solve(i + 1, sum + nums[i], nums, target) + solve(i + 1, sum - nums[i], nums, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};