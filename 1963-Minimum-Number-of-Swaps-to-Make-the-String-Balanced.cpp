class Solution {
public:
    int minSwaps(string s) {
        int closed = 0, ans = 0;
        for(int i = s.size() - 1; ~i ; --i){
            char ch = s[i];
            if(ch=='['){
                if(closed)closed--;
                else ans++, closed++;
            }
            else closed++;
        }
        return ans;
    }
};