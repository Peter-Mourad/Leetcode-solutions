class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < m;){
                int k = j, stones = 0;
                while(k < m && box[i][k]!='*'){
                    stones += box[i][k]=='#';
                    k++;
                }
                for(int ind = k - 1; ind >= j; ind--, stones--){
                    if(stones > 0) box[i][ind] = '#';
                    else box[i][ind] = '.';
                }
                j = k + 1;
            }
        }
        
        vector<vector<char>> ans(m, vector<char> (n));
        int p = 0;
        for(int j = 0;j < m;j++){
            for(int i = n - 1; ~i; i--, p++){
                ans[p / n][p % n] = box[i][j];
            }
        }
        return ans;
    }

};