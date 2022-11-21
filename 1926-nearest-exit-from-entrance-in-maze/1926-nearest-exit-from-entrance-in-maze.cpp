int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(maze.size(),vector<int> (maze[0].size()));
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                if((p.first==0 || p.first==maze.size() - 1 
                    || p.second==0 || p.second==maze[0].size() - 1) 
                   && (p.first!=entrance[0] || p.second!=entrance[1]))
                    return ans;
                for(int k = 0;k < 4;k++){
                    int nx = p.first + dx[k], ny = p.second + dy[k];
                    if(nx>=0 && nx < maze.size() 
                        && ny >= 0 && ny < maze[0].size()
                        && !vis[nx][ny] && maze[nx][ny]=='.'){
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};