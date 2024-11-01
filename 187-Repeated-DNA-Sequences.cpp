class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string cur = \\;
        map<string, int> freq;
        for(int i = 0;i < s.size();i++){
            cur += s[i];
            if(cur.size() > 10) 
                cur.erase(0,1);
            freq[cur]++;
        }
        vector<string> ans;
        for(auto p: freq){
            if(p.second > 1) 
                ans.push_back(p.first);
        }
        return ans;
    }
};