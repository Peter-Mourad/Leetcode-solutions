class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> pref(n + 1);
        for(int i = 0;i < n;i++)
            pref[i + 1] = pref[i] + (s[i]=='1');
        int ans = 0, zeroes = 0;
        for(int i = 0;i < n - 1;i++){
            zeroes += s[i]=='0';
            ans = max(ans, zeroes + pref[n] - pref[i + 1]);
        }
        return ans;
    }
};