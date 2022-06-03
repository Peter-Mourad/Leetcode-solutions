class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int> > q;
        int n = mat.size(),m = mat[0].size();
        int dx[] = {0,0,-1,1},dy[] = {-1,1,0,0};
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!mat[i][j]){
                    ans[i][j] = 0;continue;
                }
                for(int k = 0;k < 4;k++){
                    int nx = i + dx[k],ny = j + dy[k];
                    if(nx>=0 && nx< n && ny >=0 && ny < m && !mat[nx][ny]){
                        ans[i][j] = 1;
                        q.push({i,j});break;                      
                    }
                }
            }
        }
        int lvl = 1;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                ans[p.first][p.second] = lvl;
                for(int k = 0;k < 4;k++){
                    int nx = p.first + dx[k],ny = p.second + dy[k];
                    if(nx>= 0 && nx < n && ny >= 0 && ny < m 
                       && ans[nx][ny]==-1){
                        ans[nx][ny] = lvl + 1;
                        q.push({nx, ny});
                    }
                }
            }
            lvl++;
        }
        return ans;
    }
};