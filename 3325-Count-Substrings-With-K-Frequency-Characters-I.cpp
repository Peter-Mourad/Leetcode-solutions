class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        for(int i = 0;i < n;i++){
            map<char,int> f;
            int mx = 0;
            for(int j = i; j < n;j++){
                f[s[j]]++;
                mx = max(mx, f[s[j]]);
                if(mx >= k)
                    ans++;
            }
        }
        return ans;
    }
};