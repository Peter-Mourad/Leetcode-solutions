class Solution {
public:
    bool found = 0;
    int getSquare(int i, int j){
        return i / 3 * 3 + j / 3;
    }

    void solve(int ind, vector<pair<int,int>> &dots, 
    vector<vector<bool>> &row, vector<vector<bool>> &col, 
    vector<vector<bool>> &square, vector<vector<char>>& board){
        // base case: found solution
        if(ind==dots.size()){
            found = 1;
            return;
        }
        int i = dots[ind].first, j = dots[ind].second;
        // check for all valid current digits
        for(int d = 1;d <= 9;d++){
            int sq = getSquare(i,j);
            if(!row[i][d] && !col[j][d] && !square[sq][d]){
                row[i][d] = 1, col[j][d] = 1, square[sq][d] = 1;
                board[i][j] = '0' + d;
                solve(ind + 1, dots, row, col, square, board);
                if(found)
                    return;
                row[i][d] = 0, col[j][d] = 0, square[sq][d] = 0;
                board[i][j] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        // we need to keep record for each square visited digits
        // we need to keep track for each 9 cells row and 9 cells column
        // we need to store and iterate over dots cells only for optimizing time
        // backtrack and try every available digit;
        
        vector<vector<bool>> row(9,vector<bool> (10));
        vector<vector<bool>> col(9,vector<bool> (10));
        vector<vector<bool>> square(9, vector<bool>(10));
        vector<pair<int,int>> dots;
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j]!='.'){
                    int digit = board[i][j] - '0';
                    row[i][digit] = 1;
                    col[j][digit] = 1;
                    square[getSquare(i,j)][digit] = 1;
                }
                else
                    dots.push_back({i,j});
            }
        }
        solve(0, dots, row, col, square, board);
    }
};