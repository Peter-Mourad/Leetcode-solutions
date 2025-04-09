class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0] < k)return -1;
        set<int> s;
        for(int i = 0;i < nums.size();i++){
            s.insert(nums[i]);
        }
        return s.size() - (nums[0]==k);
    }
};