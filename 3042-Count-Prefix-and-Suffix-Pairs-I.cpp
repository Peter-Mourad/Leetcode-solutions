class Solution {
public:
    bool isPrefixAndSuffix(string &s1, string &s2){
        if(s1.size() > s2.size())return false;
        return s2.substr(0, s1.size())==s1 && s2.substr(s2.size() - s1.size(), s2.size())==s1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0;i < words.size(); i++){
            for(int j = i + 1;j < words.size(); j++){
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return ans;
    }
};