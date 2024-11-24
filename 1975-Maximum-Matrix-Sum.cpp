class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0, totalNeg = 0, mn = 1e18;
        for(auto row: matrix){
            for(auto a : row){
                if(a < 0) totalNeg++;
                mn = min(mn, abs(a) * 1ll);
                ans += abs(a);
            }
        }
        cout<<mn<<endl;
        return (totalNeg & 1) ? ans - mn * 2 : ans;
    }
};