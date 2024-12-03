class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        for(int i = 0, j = 0;i < s.size();i++){
            if(j < spaces.size() && spaces[j]==i) ans += ' ', j++;
            ans += s[i];
        }
        return ans;
    }
};