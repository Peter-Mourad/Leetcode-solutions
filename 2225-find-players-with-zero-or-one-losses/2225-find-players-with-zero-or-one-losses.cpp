class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        map<int,int> lost;
        for(auto a : matches){
            s.insert(a[0]);
            s.insert(a[1]);
            lost[a[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto a : s){
            if(!lost[a]){
                ans[0].push_back(a);
            }
            else if(lost[a]==1){
                ans[1].push_back(a);
            }
        }
        return ans;
    }
};