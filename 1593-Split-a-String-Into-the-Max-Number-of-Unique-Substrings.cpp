class Solution {
public:
    unordered_set<string> vis;
    int solve(int i, string& s){
        if(i==s.size())return 0;
        string cur = "";
        int ans = 0;
        for(int j = i;j < s.size();j++){
            cur += s[j];
            if(!vis.count(cur)){
                vis.insert(cur);
                ans = max(ans, solve(j + 1, s) + 1);
                vis.erase(cur);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        return solve(0,s);
    }
};