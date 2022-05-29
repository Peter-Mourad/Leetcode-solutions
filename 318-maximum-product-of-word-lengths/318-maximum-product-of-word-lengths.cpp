class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),mx = 0;
        set<int> s[n];
        for(int i = 0;i < n;i++){
            for(auto a : words[i]){
                s[i].insert(a);
            }
            for(int j = i - 1;j>=0;j--){
                bool yes = 1;
                for(auto a : s[i]){
                    if(s[j].find(a)!=s[j].end()){yes = 0;break;}
                }
                if(yes && mx < words[i].size() * words[j].size())
                    mx = words[i].size() * words[j].size();
            }
        }
        return mx;
    }
};