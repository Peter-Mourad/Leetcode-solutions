class Solution {
public:
    int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
    bool dfs(int i, int j, int n, int m,  int id, vector<vector<char>>& board, vector<vector<int>> &region, vector<vector<int>> &vis){
        vis[i][j] = 1;
        bool res = !(!i || !j || i==n - 1 || j==m - 1);
        region[i][j] = id;
        for(int k = 0; k < 4; k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
            !vis[nx][ny] && board[nx][ny]=='O'){
                vis[nx][ny] = 1;
                res &= dfs(nx, ny, n, m, id, board, region, vis);
            }
        }
        return res;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> region(n, vector<int> (m)), vis(n, vector<int> (m));
        int id = 0;
        vector<int> regions;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    regions.push_back(dfs(i, j, n, m, id++, board, region, vis));
                if(vis[i][j] && board[i][j]=='O' && regions[region[i][j]])
                    board[i][j] = 'X';
            }
        }
    }
};