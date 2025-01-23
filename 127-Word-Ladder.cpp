class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        for(int i = 0;i < wordList.size();i++){
            for(int j = i + 1; j < wordList.size(); j++){
                int diff = 0;
                for(int k = 0;k < wordList[i].size();k++){
                    diff += wordList[i][k]!=wordList[j][k];
                }
                if(diff != 1) continue;
                adj[wordList[i]].push_back(wordList[j]);
                adj[wordList[j]].push_back(wordList[i]);
            }
        }
        unordered_map<string, int> vis;
        vis[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        int cnt = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string w = q.front();
                q.pop();
                if(w==endWord) return cnt;
                for(auto w2: adj[w]){
                    if(vis.count(w2))continue;
                    vis[w2] = 1;
                    q.push(w2);
                }
            }
            cnt++;
        }
        return 0;
    }
};