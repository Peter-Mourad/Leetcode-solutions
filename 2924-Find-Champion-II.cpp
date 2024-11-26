class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inCount(n);
        for(auto edge: edges){
            inCount[edge[1]]++;
        }
        int ans = -1;
        for(int i = 0;i < n;i++){
            if(!inCount[i]){
                if(~ans) return -1;
                ans = i;
            }
        }
        return ans;
    }
};