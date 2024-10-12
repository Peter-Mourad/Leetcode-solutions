class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int> m;
        map<int, int> freq;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            m.insert(nums[i]);
            freq[nums[i]]++;
            if(i>=k - 1){
                auto it = m.end();
                it--;
                ans.push_back(*it);
                freq[nums[i - k + 1]]--;
                if(!freq[nums[i - k + 1]])
                    m.erase(nums[i - k + 1]);
            }
        }
        return ans;
    }
};