class Solution {
public:
    int n,m;
    bool valid(int i,int j){
        return (i>=0 && i < n && j < m && j>=0);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        n = grid.size(), m = grid[0].size();
        queue<pair<int,pair<int,int>> >q;
        q.push({k,{0, 0}});
        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (m,-1));
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,pair<int,int>> temp = q.front();
                q.pop();
                int i = temp.second.first, j = temp.second.second;
                if(i==n - 1 && j==m - 1){
                    return ans;
                }
                for(int l = 0;l < 4;l++){
                    int nx = i + dx[l], ny = j + dy[l];
                    if(valid(nx,ny) && vis[nx][ny] < temp.first){
                        if(grid[nx][ny] && temp.first){
                            q.push({temp.first - 1,{nx,ny}});
                            vis[nx][ny] = temp.first - 1;
                        }
                        else if(!grid[nx][ny]){
                            q.push({temp.first,{nx, ny}});
                            vis[nx][ny] = temp.first;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};