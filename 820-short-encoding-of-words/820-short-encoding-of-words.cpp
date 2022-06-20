class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto comp = [](string a, string b) -> bool{
            return (a.size() > b.size());
        };
        sort(words.begin(), words.end(), comp);
        map<string,bool> vis;
        int ans = 0;
        for(int i = 0;i < words.size();i++){
            if(vis[words[i]])continue;
            ans += words[i].size() + 1;
            string temp = "";
            for(int j = words[i].size() - 1; j >= 0; j--){
                temp = words[i][j] + temp;
                vis[temp] = 1;
            }
        }
        return ans;
    }
};