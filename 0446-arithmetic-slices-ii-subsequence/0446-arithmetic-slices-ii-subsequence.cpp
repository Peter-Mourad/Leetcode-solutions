#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0, d;
        vector <map<ll, ll>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                d = (ll)nums[i] - (ll)nums[j];
                dp[i][d] += dp[j][d] + 1;
                ans += dp[j][d];
            }
        }
        return ans;
    }
};