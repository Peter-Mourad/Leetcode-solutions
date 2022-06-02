class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> ans(m,vector<int> (n));
        for(int j = 0;j < n;j++){
            for(int i = 0;i < m;i++){
                int ind  = j * m + i;
                ans[i][j] = matrix[ind / m][ind % m];
            }
        }
        return ans;
    }
};