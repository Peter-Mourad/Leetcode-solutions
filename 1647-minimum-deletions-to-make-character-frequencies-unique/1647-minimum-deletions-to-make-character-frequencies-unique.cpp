class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for(int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;
        
        vector<int> f(s.size() + 1);
        for(int i = 25; i >= 0; i--){
            f[freq[i]]++;
        }
        int ans = 0;
        for(int i = f.size() - 1; i > 0; i--){
            if(f[i] > 1)f[i - 1] += f[i] - 1,ans += f[i] - 1;
        }
        return ans;
    }
};