class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>>, greater<> > pq;
        pq.emplace(0,0,0);
        vector<vector<int>> dis(n, vector<int> (m, 1e9));
        dis[0][0] = 0;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        while(!pq.empty()){
            auto [d,i,j] = pq.top();
            pq.pop();
            if(d > dis[i][j]) continue;
            for(int k = 0;k < 4;k++){
                int nx = i + dx[k], ny = j + dy[k], cost = !(k + 1==grid[i][j]);
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
                dis[nx][ny] > d + cost){
                    dis[nx][ny] = d + cost;
                    pq.emplace(dis[nx][ny], nx, ny);
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};