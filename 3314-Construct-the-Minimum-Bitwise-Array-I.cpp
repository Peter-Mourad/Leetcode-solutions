class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        map<int,int> res;
        for(int i = 1;i <= 1000;i++){
            if(!res.count((i | (i + 1))))
                res[(i | (i + 1))] = i;
        }
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0;i < n;i++){
            if(res.count(nums[i]))
                ans[i] = res[nums[i]];
        }
        return ans;
    }
};