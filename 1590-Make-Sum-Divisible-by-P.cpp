class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // get the shortest subarray which has subarraySum % p == totalSum % p
        int n = nums.size();
        long sum = 0;
        for(auto &a: nums)
            sum += a;
        int rem = sum % p, ans = n;
        if(!rem)
            return 0;

        vector<long> pref_mod(n + 1);
        unordered_map<long, int> vis;
        vis[0] = -1;
        for(int i = 0;i < n;i++){
            pref_mod[i + 1] = (pref_mod[i] + nums[i]) % p;
            long target = (pref_mod[i + 1] - rem + p) % p;
            if(vis.count(target))
                ans = min(ans, i - vis[target]);
            
            vis[pref_mod[i + 1]] = i;
        }
        return ans==n ? -1 : ans;
    }
};