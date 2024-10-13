class Solution {
public:
    int dp[3001][3001];

    int solve(int i, int j, string &source, string &pattern, vector<int>& targeted){
        if(i==source.size())
            return (j==pattern.size() ? 0 : INT_MIN);
        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = INT_MIN;
        if(j==pattern.size())
            return ret = solve(i + 1, j, source, pattern, targeted) + targeted[i];
        if(source[i]==pattern[j])
            ret = solve(i + 1,j + 1,source,pattern,targeted);
        return ret = max(ret, solve(i + 1, j, source, pattern, targeted) + targeted[i]);
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        vector<int> targeted(source.size());
        for(auto a: targetIndices)
            targeted[a] = 1;
        for(int i = 0;i <= source.size();i++)
            for(int j = 0;j <= pattern.size();j++)
                dp[i][j] = -1;
        int ans = solve(0, 0, source, pattern, targeted);
        return ans;
    }
};