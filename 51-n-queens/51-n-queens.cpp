class Solution {
public:
    vector<string>temp;
    vector<vector<string>>ans;
    string row;
    vector<pair<int,int>> vis;
    void solve(int i,int n){
        if(i==n){
            ans.push_back(temp);return;
        }
        for(int j = 0;j < n;j++){
            bool yes = 1;
            for(auto p : vis){
                if(abs(p.first - i)==abs(p.second - j) ||
                    j==p.second){
                    yes = 0;break;
                }
            }
            if(yes){
                string temp_row = row;
                temp_row[j] = 'Q';
                vis.push_back({i,j});
                temp.push_back(temp_row);
                solve(i + 1,n);
                vis.pop_back();
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0;i < n;i++)
            row+='.';
        
        solve(0,n);
        return ans;
    }
};