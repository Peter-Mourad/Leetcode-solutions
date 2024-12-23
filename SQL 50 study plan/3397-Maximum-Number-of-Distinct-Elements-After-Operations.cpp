class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> vis;
        int mn = -1e9;
        for(auto &a : nums) {
            if(a - k >= mn){
                a -= k;
                mn = a + 1;
            }
            else if(a - k <= mn && a + k >= mn)
                a = mn++;
            
            vis.insert(a);
        }
        return vis.size();
    }
};