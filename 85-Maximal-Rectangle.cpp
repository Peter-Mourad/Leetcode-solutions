class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> ones(r, vector<int> (c));
        for(int i = 0; i < r; i++){
            int nearest_zero = c;
            for(int j = c - 1; ~j; j--){
                if(matrix[i][j]=='1')
                    ones[i][j] = nearest_zero - j;
                else
                    nearest_zero = j;
            }
        }
        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j]=='1'){
                    int in = i, mn = ones[i][j], res = ones[i][j];
                    while(in < r && matrix[in][j]=='1'){
                        mn = min(mn, ones[in][j]);
                        res = max(res, mn * (in - i + 1));
                        in++;
                    }
                    // cout<<i + 1<<' '<<j + 1<<"__"<<in<<' '<<j + 1<<": "<<res<<endl;
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};