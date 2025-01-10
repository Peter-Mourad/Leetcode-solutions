class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mx(26);
        for(auto w: words2){
            vector<int> f(26);
            for(auto ch: w)
                f[ch - 'a']++;
            for(int i = 0;i < 26;i++)
                mx[i] = max(f[i], mx[i]);
        }
        
        vector<string> ans;
        for(auto w: words1){
            vector<int> f(26);
            for(auto ch: w)
                f[ch - 'a']++;
            bool valid = 1;
            for(int i = 0;i < 26 && valid;i++){
                if(f[i] < mx[i])
                    valid = 0;
            }
            if(valid) ans.push_back(w);
        }
        return ans;
    }
};