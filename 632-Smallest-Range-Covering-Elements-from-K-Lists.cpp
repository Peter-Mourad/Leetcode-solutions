class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<pair<int,int> > v;
        for(int i = 0, p = 0;i < n;i++){
            for(auto &a: nums[i])
                v.push_back({a, i});
        }
        sort(v.begin(), v.end());
        vector<int> prev(n, INT_MIN);
        vector<int> ans = {-100000, 100000};
        int mn = INT_MIN, vis = 0;
        for(int i = 0;i < v.size(); i++){
            if(prev[v[i].second]==INT_MIN) vis++;
            
            prev[v[i].second] = v[i].first;
            int mn = *min_element(prev.begin(), prev.end());
            if(vis==n){
                if(ans[1] - ans[0] > v[i].first - mn){
                    ans[0] = mn, ans[1] = v[i].first;
                }
            }
        }
        return ans;
    }
};