class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        int found = -1;
        for(int i = 0;i < n;i++){
            if(end==bank[i]){
                found = i;break;
            }
        }
        if(found==-1){
            return -1;
        }
        
        // map start, end, bank strings to indexes and make adjcanency list      
        vector<int> adj[12];
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                int cnt_diff = 0;
                for(int in = 0;in < 8;in++){
                    if(bank[i][in]!=bank[j][in])
                        cnt_diff++;
                }
                if(cnt_diff==1)
                    adj[i].push_back(j), adj[j].push_back(i);
            }
            int cnt_diffs = 0;
            for(int in = 0;in < 8;in++){
                if(bank[i][in]!=start[in])
                    cnt_diffs++;
            }
            if(cnt_diffs==1)
                adj[i].push_back(n), adj[n].push_back(i);
        }
        // run bfs from n
        queue<int> q;
        q.push(n);
        vector<bool> vis(n + 2);
        vis[n] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int a = q.front();
                q.pop();
                if(a==found){
                    return ans;
                }
                for(auto b : adj[a]){
                    if(!vis[b]){
                        q.push(b);
                        vis[b] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};