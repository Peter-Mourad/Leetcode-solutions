class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0;i < words.size(); i++){
            int n = words[i].size();
            for(int j = i + 1;j < words.size(); j++){
                if(words[i].size() > words[j].size()) continue;
                int m = words[j].size();
                ans += !words[j].find(words[i]) && words[j].rfind(words[i])==m - n;
            }
        }
        return ans;
    }
};