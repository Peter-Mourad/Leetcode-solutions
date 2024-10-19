class Solution {
public:
    char findKthBit(int n, int k) {
        /* 
            the pattern in this problem is for every operation
            we realize that the string is an inverted palindrome
            i can identify the inverted palindrome as odd sized palindrome
            with 1 in the middle and the first half is the inversion of
            the second half
        */

        string ans = "0";
        for(int i = 2; i <= n && ans.size() < k; i++){
            ans += '1';
            for(int j = ans.size() - 2; ~j ; j--)
                ans += ((ans[j] - '0') ^ 1) + '0';
        }
        return ans[--k];
    }
};