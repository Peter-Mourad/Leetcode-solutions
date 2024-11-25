class Solution {
public:
    bool valid(int i, int j){
        return i >= 0 && i < 2 && j>=0 && j < 3;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<vector<int>>, bool> vis;
        int ans = 0;
        queue<vector<vector<int>>> q;
        q.push(board);
        int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
        vector<vector<int>> need = {{1,2,3}, {4,5,0}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto temp = q.front();
                q.pop();
                if(need == temp) return ans;
                if(vis[temp]) continue;
                vis[temp] = 1;
                for(int i = 0;i < 2;i++){
                    for(int j = 0;j < 3;j++){
                        if(!temp[i][j]){
                            for(int k = 0;k < 4;k++){
                                int nx = i + dx[k], ny = j + dy[k];
                                if(valid(nx,ny)){
                                    swap(temp[i][j], temp[nx][ny]);
                                    if(!vis[temp])
                                        q.push(temp);
                                    swap(temp[i][j], temp[nx][ny]);
                                }
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};