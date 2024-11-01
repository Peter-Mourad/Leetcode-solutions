class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(auto a : s){
            if(ans.size() >= 2 && ans[ans.size() - 2]==a && ans.back()==a)
                continue;
            ans += a;
        }
        return ans;
    }
};