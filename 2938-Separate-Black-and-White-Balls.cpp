class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, white = 0;
        for(int i = 0;i < s.size();i++)
            (s[i]=='0') ? ans += white : white++;
        
        return ans;
    }
};