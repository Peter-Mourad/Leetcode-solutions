class Solution {
public:
    int dp[1000][1000];
    int solve(int l,int r, string &s){
        // base case
        if(l >= r)return 1;
        // checking state is answered before
        if(dp[l][r]!=-1)return dp[l][r];
        // initialize
        dp[l][r] = 0;
        // getting answer
        if(s[l]==s[r])
            return dp[l][r] = solve(l + 1,r - 1,s);
        return dp[l][r] = 0;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof dp);
        int mx = 0;
        string ans;
        for(int i = 0;i < s.size();i++){
            string temp = "";
            for(int j = i;j < s.size();j++){
                temp+=s[j];
                if(solve(i,j,s) && j - i + 1 > mx){
                    ans = temp;
                    mx = j - i + 1;
                }
            }
        }
        return ans;
    }
};