class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        int sz = n * n;
        vector<int> board(sz + 1);
        for(int i = n - 1, d = 0, no = 1; ~i; i--, d^=1){
            for(int j = (d & 1 ? n - 1 : 0); j >= 0 && j < n; (d & 1 ? j-- : j++), no++){
                board[no] = (~b[i][j] ? b[i][j] : no);
            }
        }
        queue<int> q;
        q.push(1);
        int ans = 0;
        vector<bool> vis(sz + 1);
        while(!q.empty()){
            int queueSZ = q.size();
            while(queueSZ--){
                int a = q.front();
                vis[a] = 1;
                q.pop();
                if(a==sz)return ans;
                for(int i = 1; a + i <= sz && i <= 6; i++){
                    if(a + i)
                    if(vis[board[a + i]])continue;
                    vis[board[a + i]] = 1;
                    q.push(board[a + i]);
                }
            }
            ans++;
        }
        return -1;
    }
};