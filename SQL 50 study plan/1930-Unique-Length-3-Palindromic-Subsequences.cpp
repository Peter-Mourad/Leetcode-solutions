class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> pref(n + 1, vector<int> (26));
        vector<pair<int,int>> range(26);
        for(int i = 0;i < 26;i++) range[i] = {INT_MAX, INT_MIN};
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 26;j++)
                pref[i + 1][j] = pref[i][j];
            pref[i + 1][s[i] - 'a']++;
            range[s[i] - 'a'].first = min(range[s[i] - 'a'].first, i);
            range[s[i] - 'a'].second = max(range[s[i] - 'a'].second, i);
        }
        int ans = 0;
        for(int i = 0;i < 26;i++){
            if(range[i].first == INT_MAX)continue;
            int l = range[i].first, r = range[i].second;
            for(int j = 0;j < 26;j++){
                ans += (pref[r][j] - pref[l + 1][j] > 0 ? 1 : 0);
            }
        }
        return ans;
    }
};