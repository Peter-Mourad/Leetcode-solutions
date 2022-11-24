int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
class Solution {
public:
    int n,m,sz;
    bool vis[6][6];
    bool dfs(int i,int j, int cur, string &word, vector<vector<char>>& board){
        vis[i][j] = 1;
        if(cur==sz - 1)return 1;
        bool found = 0;
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
               !vis[nx][ny] && board[nx][ny]==word[cur + 1]){
                found |= dfs(nx, ny, cur + 1, word, board);
            }
        }
        vis[i][j] = 0;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), sz = word.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, 0, word, board))
                        return 1;
                }
            }
        }
        return 0;
    }
};