class Solution {
public:
    int dp[22][32],n,m;
    string s,p;
    bool solve(int i,int j){
        int &ret = dp[i][j];
        if(i==n && j==m) return ret = 1;
        if(j==m) return ret = 0;    
        if(~ret)return ret;
        
        // either character , char & '*', '.', '.' & '*'
        if(s[i]==p[j]){
            if(j + 1 < m && p[j + 1]=='*'){
                ret = 0;
                int k = i;
                for(;k < n && s[k]==s[i];k++){
                    ret|=solve(k,j + 2);
                }
                ret|=solve(k,j + 2);
                return ret;
            }
            return ret = solve(i + 1,j + 1);
        }
        else if(p[j]=='.'){
            if(j + 1 < m && p[j + 1]=='*'){
                ret = 0;
                for(int k = i;k <= n;k++){
                    ret|=solve(k,j + 2);
                }
                return ret;
            }
            return ret = solve(i + 1,j + 1);
        }
        else {
            if(j + 1 < m && p[j + 1]=='*')
                return ret = solve(i,j + 2);
            return ret = 0;
        }
    }
    bool isMatch(string a, string b) {
        memset(dp,-1,sizeof dp);
        s = a,p = b;
        n = s.size(),m = p.size();
        return solve(0,0);
    }
};