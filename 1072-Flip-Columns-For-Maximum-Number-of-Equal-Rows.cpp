class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // try to make all values 0 or 1 first see the flips for every row needed
        // and get the max matches
        int n = matrix.size(), m = matrix[0].size();
        map<vector<int>, int> freq;
        for(auto row: matrix){
            vector<int> res , res2;
            for(int i = 0;i < row.size();i++){
                if(row[i]) res.push_back(i);
                else res2.push_back(i);
            }
            freq[res]++;
            freq[res2]++;
        }
        int ans = 1;
        for(auto p: freq){
            ans = max(ans, p.second);
        }
        return ans;
    }
};