class Solution {
public:
    int dp[200][200],n,m;
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    int solve(int i,int j,vector<vector<int>>&x){
        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = 0;
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k],ny = j + dy[k];
            if(nx>=0 && nx < n && ny>=0 && ny < m &&
               x[nx][ny] > x[i][j]){
                ret = max(ret,solve(nx,ny,x));
            }
        }
        return ret += 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        n = matrix.size(),m = matrix[0].size();
        int ans = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans;
    }
};