class WordFilter {
public:
    map<string, int> mp;
    WordFilter(vector<string>& words) {
        for(int i = 0;i < words.size();i++){
            string pref = "",suff = "";
            vector<string> s;
            for(int k = words[i].size() - 1;suff.size() < 10 && k                      >= 0;k--){
                suff = words[i][k] + suff;
                s.push_back(suff);
            }
            
            for(int j = 0;j < 10 && j < words[i].size();j++){
                pref+=words[i][j];
                for(auto a : s){
                    mp[pref + '|' + a] = i + 1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix + '|' + suffix] - 1;
    }
};