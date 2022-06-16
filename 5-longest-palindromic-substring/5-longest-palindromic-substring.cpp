class Solution {
public:
    int dp[1000][1000];
    int solve(int i, int j, string &s){
        int &ret = dp[i][j];
        if(i > j)return 0;
        if(~ret)return ret;
        if(i==j)return ret = 1;
        if(s[i]==s[j])return ret = 2 + solve(i + 1,j - 1, s);
        return ret = -1e9;
    }
    string longestPalindrome(string s) {
        for(int i = 0;i < s.size();i++){
            for(int j = i;j < s.size();j++)
                dp[i][j] = -1;
        }
        int mx = 1;
        pair<int,int> res;
        for(int i = 0;i < s.size();i++){
            for(int j = i + 1;j < s.size();j++){
                if(solve(i,j,s) > mx){
                    mx = solve(i,j,s);
                    res = {i,j};
                }
            }
        }
        string ans = "";
        for(int i = res.first;i <= res.second;i++)
            ans+=s[i];
        
        return ans;
    }
};