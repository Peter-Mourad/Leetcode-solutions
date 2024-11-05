class Solution {
public:
    int minChanges(string s) {
        int ans = 0, n = s.size();
        for(int i = 0;i < n;){
            int j = i;
            while(j < n && s[i]==s[j])
                j++;
            if((j - i) & 1){
                ans++, s[j - 1] = (s[j - 1] - '0' ^ 1) + '0';
                i = j - 1;
            }
            else
                i = j;
        }
        return ans;
    }
};