class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        long long ans = 0;
        for(int i = 0;i < nums.size();i++){
            ans += i - freq[i - nums[i]];
            freq[i - nums[i]]++;
        }
        return ans;
    }
};