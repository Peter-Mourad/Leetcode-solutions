class Solution {
public:
    int dp[202][102];
    string x1, x2, x3;
    // dp with state index of the target string and first string
    int solve(int i,int j){
        // if the string is finished return true
        if(i==x3.size())return 1;
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 0;
        // get index of the second string
        int k = i - j;
        if(j < x1.size() && x3[i]==x1[j])
            ret|= solve(i + 1, j + 1);
        if(k < x2.size() && x3[i]==x2[k])
            ret|=solve(i + 1, j);
        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        // store strings in global variables
        x1 = s1, x2 = s2, x3 = s3;
        // initialize the dp array
        for(int i = 0; i <= s3.size(); i++)
            for(int j = 0; j <= s1.size(); j++)
                dp[i][j] = -1;
        return solve(0, 0);
    }
};