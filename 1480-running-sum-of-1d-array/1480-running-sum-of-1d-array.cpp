class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum(nums.size());
        for(int i = 0;i < nums.size();i++){
            if(i)
                sum[i] = sum[i - 1];
            sum[i]+=nums[i];
        }
        return sum;
    }
};