class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        bool palindrome = true;
        for(int i = 0,j = n - 1;i < j;i++,j--){
            if(s[i]!=s[j]){
                palindrome = false;break;
            }
        }
        return (palindrome ? 1 : 2);
    }
};