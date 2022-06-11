class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        set<pair<int,int> > pref,suff;
        int n = nums.size(),sum1 = 0,sum2 = 0;
        pref.insert({0, 0}),suff.insert({0, 0});
        for(int i = 0,j = n - 1;i < n;i++,j--){
            sum1+=nums[i];
            sum2+=nums[j];
            pref.insert({sum1,i + 1});
            suff.insert({sum2,n - j});
        }
        sum1 = 0,sum2 = 0;
        pair<int,int> ans = {n,-1};
        for(int i = 0,j = n - 1;i < n;i++,j--){
            sum1+= nums[i], sum2+=nums[j];
            auto it = pref.lower_bound({x - sum2 + 1,0});
            it--;
            if((*it).first==x - sum2 && (*it).second + (n - j) <= n){
                ans = {min(ans.first,((*it).second + (n - j))), 1};
            }
            
            auto it2 = suff.lower_bound({x - sum1 + 1,0});
            it2--;
            if((*it2).first==x - sum1 && (*it2).second + (i + 1) <= n)
                ans = {min(ans.first,((*it2).second + (i + 1))), 1};
        }
        return (ans.second!=-1 ? ans.first : ans.second);
    }
};