class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> s;
        vector<bool> vis(nums.size());
        for(int i = 0;i < nums.size();i++){
            s.insert({nums[i], i});
        }
        long long ans = 0;
        while(!s.empty()){
            auto p = *s.begin();
            s.erase(s.begin());
            ans += p.first;
            vis[p.second] = 1;
            if(p.second && !vis[p.second - 1])
                vis[p.second - 1] = 1, s.erase({nums[p.second - 1], p.second - 1});
            if(p.second < nums.size() - 1 && !vis[p.second + 1])
                vis[p.second + 1] = 1, s.erase({nums[p.second + 1], p.second + 1});   
        }
        return ans;
    }
};