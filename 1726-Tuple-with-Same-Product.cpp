class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> f;
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = i + 1;j < nums.size();j++){
                ans += f[nums[i] * nums[j]] * 8;
                f[nums[i] * nums[j]]++;
            }
        }
        return ans;
    }
};