#define ll long long
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ll sum = 0, n = nums.size();
        for(int i = 0;i < n;i++)
            sum+=nums[i];   
        sort(nums.begin(),nums.end());
        ll cur = 0, ans = 2e18;
        for(ll i = 0;i < n;i++){
            ans = min(abs((ll)nums[i] * i - cur) + 
              abs((ll)nums[i] * (n - i - 1) - (sum - cur - nums[i])),ans);
            cur+=nums[i];
        }
        return ans;
    }
};