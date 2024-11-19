class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long ans = 0, sum = 0;
        for(int i = 0;i < nums.size(); i++){
            freq[nums[i]]++;
            sum += nums[i];
            if(i > k - 1){
                freq[nums[i - k]]--;
                sum -= nums[i - k];
                if(!freq[nums[i - k]]) freq.erase(nums[i - k]);
            }
            if(freq.size()==k)
                ans = max(ans, sum);
        }
        return ans;
    }
};