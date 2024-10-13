class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0;i < n;i++){
            if(nums[i] % 2==0)continue;
            for(long long j = 1;j < 31;j++){
                if(!(nums[i] & ((long long)1<<j))){
                    j--;
                    nums[i] ^= (long long)1<<j;
                    break;
                }
            }
            ans[i] = nums[i];
        }
        return ans;
    }
};