class Solution {
public:
    static bool comp(pair<int,int> p1, pair<int, int> p2){
        if(p1.first > p2.first || 
        (p1.first==p2.first && p1.second > p2.second)) return true;
        return false;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for(int i = 0;i + k <= n;i++) {
            map<int,int> freq;
            for(int j = i;j < i + k; j++)
                freq[nums[j]]++;

            vector<pair<int,int>> f;
            for(auto &p: freq)
                f.push_back({p.second, p.first});
            
            sort(f.begin(), f.end(), comp);

            for(int p = 0;p < min((int)f.size(), x);p++)
                ans[i] += f[p].first * f[p].second;
        }
        return ans;
    }
};