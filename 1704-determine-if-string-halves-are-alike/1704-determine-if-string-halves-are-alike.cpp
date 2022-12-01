class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        for(int i = 0;i < s.size();i++){
            s[i] = tolower(s[i]);
            if(s[i]=='a' || s[i] == 'e' || s[i]=='o' || s[i]=='u' || s[i]=='i')
                cnt+=(i < s.size() / 2 ? 1 : -1);
        }
        return !cnt;
    }
};