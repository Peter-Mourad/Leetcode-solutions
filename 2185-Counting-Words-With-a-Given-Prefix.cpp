class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto word: words){
            if(word.substr(0, pref.size()) == pref)
                cnt++;
        }
        return cnt;
    }
};