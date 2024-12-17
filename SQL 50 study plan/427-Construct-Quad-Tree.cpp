/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int count(int i1, int j1, int i2, int j2, vector<vector<int>> &pref){
        int res = pref[i2][j2];
        if(i1) res -= pref[i1 - 1][j2];
        if(j1) res -= pref[i2][j1 - 1];
        if(i1 && j1) res += pref[i1 - 1][j1 - 1];
        return res;
    }

    void solve(int i1, int j1, int i2, int j2, Node* cur, vector<vector<int>> &pref){
        int rows = (i2 - i1 + 1), cols = (j2 - j1 + 1);
        int sz = rows * cols;
        int cnt = count(i1,j1,i2,j2,pref);
        if(sz==cnt || !cnt){ // it's a leaf
            cur->isLeaf = true;
            cur->val = cnt == sz;
            return;
        }
        cur->val = 1;
        
        // else then divide to 4 quarters
        // top left from i1, j1, to i1 + rows / 2 - 1, j1 + cols / 2 - 1
        cur->topLeft = new Node();
        solve(i1, j1, i1 + rows / 2 - 1, j1 + cols / 2 - 1, cur->topLeft, pref);
        // top right from i1, j1 + cols / 2 to i1 + rows / 2 - 1, j2
        cur->topRight = new Node();
        solve(i1, j1 + cols / 2, i1 + rows / 2 - 1, j2, cur->topRight, pref);
        // bottom left from i1 + rows / 2, j1 to i2, j1 + cols / 2 - 1
        cur->bottomLeft = new Node();
        solve(i1 + rows / 2, j1, i2, j1 + cols / 2 - 1, cur->bottomLeft, pref);
        // bottom right from i1 + rows / 2, j1 + cols / 2 to i2 , j2
        cur->bottomRight = new Node();
        solve(i1 + rows / 2, j1 + cols / 2, i2, j2, cur->bottomRight, pref);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> pref(n, vector<int> (n));
        pref[0][0] = grid[0][0];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(!i && !j) continue;
                if(i) pref[i][j] += pref[i - 1][j];
                if(j) pref[i][j] += pref[i][j - 1];
                if(i && j) pref[i][j] -= pref[i - 1][j - 1];
                pref[i][j] += grid[i][j];
            }
        }

        // recursively iterate over the grid and quarterize it till reach leafs
        Node* root = new Node();
        solve(0, 0, n - 1, n - 1, root, pref);
        return root;
    }
};