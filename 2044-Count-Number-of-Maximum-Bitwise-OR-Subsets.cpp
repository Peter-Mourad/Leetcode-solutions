class Solution {
public:
    int solve(int i, int curOr, int need, vector<int> &nums) {
        if(i==nums.size())
            return curOr==need;
        return solve(i + 1, curOr | nums[i], need, nums) + 
        solve(i + 1, curOr, need, nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int need = 0;
        for(auto a : nums) 
            need |= a;
        return solve(0,0,need,nums);
    }
};