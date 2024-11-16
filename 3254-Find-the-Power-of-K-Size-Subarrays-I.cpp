class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int leftSorted = 0, ind = 0;
        vector<int> ans(nums.size() - k + 1);
        for(int i = 0; i < nums.size();i++){
            if(i && nums[i] != nums[i - 1] + 1)
                leftSorted = i;
            if(i >= k - 1)
                ans[ind++] = (i - leftSorted + 1 >= k) ? nums[i] : -1;
        }
        return ans;
    }
};