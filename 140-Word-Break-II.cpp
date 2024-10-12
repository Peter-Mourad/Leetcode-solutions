class Solution {
public:
    vector<string> ans;
    string cur = "";
    void solve(int i, string &s, map<string, bool> &vis){
        if(i==s.size()){
            ans.push_back(cur);
            return;
        }
        string word = "";
        for(int j = i;j < s.size();j++){
            word += s[j];
            
            if(vis[word]){
                cur += word;
                if(j != s.size() - 1)
                    cur += ' ';
                solve(j + 1, s, vis);
                if(j != s.size() - 1)
                    cur.pop_back();
                int sz = word.size();
                while(sz--) 
                    cur.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // approach:
        // map all prefixes of wordDict
        // while the prefix of s found continue till it completes a word 
        // decide to take or not take this word since the words are unique it will differ in size only

        map<string, bool> vis;
        for(auto &word: wordDict){
            string temp = "";
            vis[word] = 1;
        }
        solve(0, s, vis);
        return ans;
    }
};