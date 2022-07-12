class Solution {
public:
    int l,n;
    vector<int> temp;
    int sum[4];
    bool solve(int i, vector<int>& matchsticks){
        if(i==n){
            bool res = 1;
            for(int j = 0;j < 4;j++)
                res &= (sum[j]==l);
            return res;
        }
        bool ans = 0;
        for(int j = 0;j < 4 && !ans;j++){
            if(sum[j] + matchsticks[i] <= l){
                sum[j] += matchsticks[i];
                ans |= solve(i + 1, matchsticks);
                sum[j] -= matchsticks[i];
            }
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto a : matchsticks)
            sum += a;
        if(sum % 4 != 0 || matchsticks.size() < 4)
            return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        l = sum / 4, n = matchsticks.size();
        for(auto a : matchsticks)
            if(a > l)return false;
        return solve(0, matchsticks);
    }
};