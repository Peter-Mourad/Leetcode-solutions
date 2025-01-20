class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> r(n), c(m);
        unordered_map<int, vector<pair<int,int>> > pos;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                pos[mat[i][j]].push_back({i,j});

        for(int k = 0;k < arr.size();k++){
            for(auto [i, j]: pos[arr[k]]){
                r[i]++;
                c[j]++;
                if(r[i]==m || c[j]==n) 
                    return k;
            }
        }
        return 0;
    }
};