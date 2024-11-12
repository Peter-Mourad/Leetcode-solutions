class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long curProduct = 1, ans = 0, l = 0;
        for(int i = 0;i < nums.size();i++){
            curProduct *= nums[i];
            while(curProduct >= k && l <= i)
                curProduct /= nums[l++];

            ans += i - l + 1;
        }
        return ans;
    }
};