class Solution {
public:
    vector<string> ans;
    string temp = "";
    int n;
    void solve(int i, string &s){
        if(i==n){
            ans.push_back(temp);return;
        }
        if(s[i]>='0' && s[i] <= '9'){
            temp+=s[i];
            solve(i + 1,s);
            temp.pop_back();
        }
        else{
            temp+=tolower(s[i]);
            solve(i + 1,s);
            temp.pop_back();
            temp+=toupper(s[i]);
            solve(i + 1,s);
            temp.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        n = s.size();
        solve(0,s);
        return ans;
    }
};