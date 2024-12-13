class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // first get the max pairs from the end of 32
        // then iterate from the begining over possible 1s
        vector<pair<int, int>> pairs;
        set<int> s;
        s.insert(nums.back());
        for(int i = nums.size() - 2; ~i; i--){
            auto it = s.lower_bound(nums[i]);
            if(it == s.begin()) {
                s.insert(nums[i]);
                continue;
            }
            it--;
            int no = *it;
            // if the 2nd number no is not bigger than the last taken
            // pair then it's useless
            if(pairs.empty() || (!pairs.empty() && no > pairs.back().first))
                pairs.push_back({no, i});
            s.insert(nums[i]);
        }
        sort(pairs.begin(), pairs.end());
        for(int i = 0;i < nums.size();i++){
            // we need to get the first pair that has 2nd > nums[i]
            int ind = lower_bound(pairs.begin(), pairs.end(), make_pair(nums[i] + 1, i + 1)) - pairs.begin();
            if(ind < pairs.size() && pairs[ind].second > i)
                return true;
        }
        return false;
    }
};