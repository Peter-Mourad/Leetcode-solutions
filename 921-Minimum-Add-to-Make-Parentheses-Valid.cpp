class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0,ans = 0;
        for(auto ch: s){
            if(ch=='(') open++;
            else (!open) ? ans++ : open--;
        }
        return ans + open;
    }
};