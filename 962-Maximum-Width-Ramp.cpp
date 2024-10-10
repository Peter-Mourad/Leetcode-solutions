class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n + 1);
        for(int i = n - 1, j = 0; ~i; --i,j++){
            mx[j + 1] = max(mx[j], nums[i]);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            int l = upper_bound(mx.begin(), mx.end(), nums[i] - 1) - mx.begin();
            l = max(l,1);
            ans = max(ans, n - l - i);
        }
        return ans;
    }
};