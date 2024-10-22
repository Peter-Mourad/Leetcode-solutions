class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string cur = "";
        for(int i = 0;i < target.size();i++){
            cur+='a';
            ans.push_back(cur);
            while(cur.back() < target[i]){
                cur.back()++;
                ans.push_back(cur);
            }
        }
        return ans;
    }
};