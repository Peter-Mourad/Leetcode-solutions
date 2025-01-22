class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // run bfs from water cells
        queue<pair<int,int>> q;
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int> (m)), vis(n, vector<int> (m));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m; j++){
                if(isWater[i][j]) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int cur = 0;
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();
                ans[i][j] = cur;
                for(int k = 0; k < 4; k++){
                    int nx= i + dx[k], ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            cur++;
        }
        return ans;
    }
};