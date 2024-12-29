class Solution {
public:
    long long dp[1000][1000], mod = 1e9 + 7;
    int mul(long long a, long long b){
        return ((a % mod) * (b % mod)) % mod;
    }

    int add(long long a, long long b){
        return ((a % mod) + (b % mod)) % mod;
    }

    int solve(int i, int j, string &target, vector<vector<int> > &chars){
        if(i==target.size())return 1;
        if(j == 1000)return 0;
        long long &ret = dp[i][j];
        if(~ret) return ret;
        ret = 0;
        if(chars[j][target[i] - 'a'])
            ret = mul(solve(i + 1, j + 1, target, chars), chars[j][target[i] - 'a']);
        return ret = add(ret, solve(i, j + 1, target, chars));
    }

    int numWays(vector<string>& words, string target) {
        vector<vector<int> > chars(1000, vector<int> (26));
        memset(dp, -1, sizeof(dp));
        for(auto word: words){
            for(int i = 0;i < word.size();i++){
                chars[i][word[i] - 'a']++;
            }
        }
        return solve(0, 0, target, chars);
    }
};