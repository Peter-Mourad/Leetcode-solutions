class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<double, long long> freq;
        long long ans = 0;
        for(int r = 4; r < nums.size(); ++r){
            for(int p = 0, q = r - 2; p < q - 1; ++p) 
                freq[nums[p] * 1.0 / nums[q]]++;
            for(int s = r + 2; s < nums.size(); ++s) 
                ans += freq[nums[s] * 1.0 / nums[r]];
        }
        return ans;
    }
};