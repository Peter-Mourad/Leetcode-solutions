class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        multiset<pair<int,int> > sorted;
        for(auto interval: intervals)
            sorted.insert({interval[0], interval[1]});
        int ans = 0;
        while(!sorted.empty()){
            ans++;
            int st = 0;
            while(true){
                auto l = sorted.lower_bound({st,st});
                if(l==sorted.end())break;
                st = (*l).second + 1;
                sorted.erase(l);
            }
        }
        return ans;
    }
};