class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp = "";
        for(int i = 0;i < s.size();i++){
            if(s[i]==' '){
                if(temp!="")
                    v.push_back(temp);
                temp = "";
            }
            else
                temp+=s[i];
        }
        if(temp!="")
            v.push_back(temp);
        reverse(v.begin(),v.end());
        string ans = "";
        for(auto st : v)
            ans+=st + ' ';
        ans.pop_back();
        return ans;
    }
};