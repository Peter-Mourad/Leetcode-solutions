class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> vis(32,-2);
        int mask = 0, ans = 0;
        vis[0] = -1;
        for(int i = 0;i < s.size();i++){
            if(s[i]=='a') mask^=1;
            if(s[i]=='e') mask^=2;
            if(s[i]=='i') mask^=4;
            if(s[i]=='o') mask^=8;
            if(s[i]=='u') mask^=16;
            if(vis[mask] > -2)
                ans = max(ans, i - vis[mask]);
            else
                vis[mask] = i;
        }
        return ans;
    }
};