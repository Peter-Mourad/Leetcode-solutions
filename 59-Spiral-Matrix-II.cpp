class Solution {
public:
    bool valid(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    vector<vector<int>> generateMatrix(int n) {
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
        int dir = 0, cur = 1, i = 0, j = 0;
        vector<vector<int> > ans(n, vector<int> (n));
        while(cur <= n * n){
            ans[i][j] = cur++;
            if(valid(i + dx[dir], j + dy[dir], n) && !ans[i + dx[dir]][j + dy[dir]])
                i += dx[dir], j += dy[dir];
            else{
                dir = (dir + 1) % 4;
                i += dx[dir], j += dy[dir];
            }
        }
        return ans;
    }
};