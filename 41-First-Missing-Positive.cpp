class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            while(nums[i] <= nums.size() && nums[i] >= 1 && nums[nums[i] - 1]!=nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
            }
        }   
        int ans = 0;
        for(;ans < nums.size() && nums[ans]==ans + 1; ans++){}
        return ans + 1;
    }
};