class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp(nums.size());
        temp[0] = nums[0];
        int n = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < temp[0])
                temp[0] = nums[i];
            else if(nums[i] > temp[n - 1])
                temp[n++] = nums[i];
            else{
                int in = lower_bound(temp.begin(),temp.begin() + n, nums[i]) - temp.begin();
                temp[in] = nums[i];
            }
        }
        return n;
    }
};