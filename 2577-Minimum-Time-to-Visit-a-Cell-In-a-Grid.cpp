class Solution {
public:

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0]>1 && grid[0][1]>1)  return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}});
        vis[0][0] = 0;
        int dx[] = {0,0,1,-1}, dy[] = {1, -1, 0, 0};
        while(!q.empty()){
            int dis = q.top().first, i = q.top().second.first, j = q.top().second.second;
            q.pop();
            if(i== n - 1 && j == m - 1) return dis;
            for(int k = 0;k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        int w = ((grid[nx][ny] - dis) & 1) ? 0 : 1;
                        int nextTime = max(dis + 1, grid[nx][ny] + w);
                        if (nextTime < vis[nx][ny]) {
                            vis[nx][ny] = nextTime;
                            q.push({nextTime, {nx,ny}});
                        }
                    }
            }
        }
        return -1;
    }
};