class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size(), j = 0;
        for(int i = 0;i < n && j < m;i++){
            char nxt = (s1[i] - 'a' + 1) % 26 + 'a';
            if(s1[i]==s2[j] || nxt==s2[j])
                j++;
        }
        return j==m;
    }
};