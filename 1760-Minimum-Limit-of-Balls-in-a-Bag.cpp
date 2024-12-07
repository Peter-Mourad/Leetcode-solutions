class Solution {
public:
    bool ok(int mx, vector<int> &nums, int maxOperations){
        long long need = 0;
        for(auto a : nums){
            if(a <= mx) continue;
            need += (a + mx - 1) / mx - 1;
        }
        return need <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1,r = 1e9, mid, ans = INT_MAX;
        while(l <= r){
            mid = (l + r) / 2;
            if(ok(mid, nums, maxOperations))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return ans;
    }
};