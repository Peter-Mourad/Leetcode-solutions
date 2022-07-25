class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int in1 = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(in1==nums.size())return {-1,-1};
        if(nums[in1]!=target)return {-1,-1};
        int in2 = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
        vector<int> ans = {in1,in2};
        return ans;
    }
};