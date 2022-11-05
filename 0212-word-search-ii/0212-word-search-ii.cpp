int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};
bool vis[12][12];
class Solution {
public:
    unordered_map<string,bool> in, found;
    string temp = "";
    int n,m,mx;
    void solve(int tot, int i, int j, vector<vector<char>>& board){
        if(in.find(temp)==in.end())return;
        if(tot==10)
            return;
        
        temp+=board[i][j];
        found[temp] = 1;
        vis[i][j] = 1;
        for(int k = 0;k < 4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >=0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                solve(tot + 1, nx, ny, board);
        }
        vis[i][j] = 0;
        temp.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        in[""] = 1;
        for(auto a : words){
            string pref = "";
            for(auto b : a){
                pref+=b;
                in[pref] = 1;
            }
        }
        n = board.size(), m = board[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                solve(0, i, j, board);
            }
        }
        vector<string>ans;
        for(auto &a : words){
            if(found[a])
                ans.push_back(a);
        }
        return ans;
    }
};