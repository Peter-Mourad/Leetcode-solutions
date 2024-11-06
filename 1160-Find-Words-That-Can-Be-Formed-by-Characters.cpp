class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> vis(26);
        for(auto a: chars) 
            vis[a - 'a']++;

        int ans = 0;
        for(auto word: words){
            bool valid = 1;
            vector<int> temp = vis;
            for(auto a: word){
                if(!temp[a - 'a']){
                    valid = 0;
                    break;
                }
                temp[a - 'a']--;
            }
            ans += valid ? word.size() : 0;
        }
        return ans;
    }
};