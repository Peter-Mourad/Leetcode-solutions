int dp[50003],n;
vector<pair<int,pair<int,int>> >v;
class Solution {
public:
    int solve(int i){
        if (i>=n)return 0;
        int &ret = dp[i];
        if(~ret)return ret;
        ret = 0;
        int next = i + 1;
        for(;next < n;next++){
            if(v[next].first >= v[i].second.first)
                break;
        }
        return ret = max(solve(i + 1), solve(next) + v[i].second.second);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof dp);
        n = profit.size();
        v.resize(n);
        for(int i = 0;i < profit.size();i++){
            v[i] = {startTime[i],{endTime[i],profit[i]}};
        }
        sort(v.begin(),v.end());
        return solve(0);
    }
};