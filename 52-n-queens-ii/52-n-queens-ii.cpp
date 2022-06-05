class Solution {
public:
    vector<pair<int,int>> vis;
    int solve(int i,int n){
        if(i==n)
            return 1;
        
        int ans = 0;
        for(int j = 0;j < n;j++){
            bool yes = 1;
            for(auto p : vis){
                if(abs(p.first - i)==abs(p.second - j) ||
                    j==p.second){
                    yes = 0;break;
                }
            }
            if(yes){
                vis.emplace_back(i,j);
                ans += solve(i + 1,n);
                vis.pop_back();
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        return solve(0,n);
    }
};