class Solution {
public:
    int minimumLength(string s) {
        vector<int> f(26);
        for(auto ch: s){
            f[ch - 'a']++;
        }
        int ans = 0;
        for(int i = 0;i < 26;i++){
            if(f[i]) ans += (f[i] & 1 ? 1 : 2);
        }
        return ans;
    }
};