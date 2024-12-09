class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> similar;
        for(int i = 1;i < nums.size();i++){
            if((nums[i] & 1) == (nums[i - 1] & 1))
                similar.push_back(i - 1);
        }

        int q = queries.size();
        vector<bool> ans(q);
        for(int i = 0;i < q;i++){
            auto l = lower_bound(similar.begin(), similar.end(),queries[i][0]) - similar.begin();
            if(!(l < similar.size() && similar[l] < queries[i][1]))
                ans[i] = 1;
        }
        return ans;
    }
};