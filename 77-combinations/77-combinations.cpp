class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void solve(int i,int &n,int &k,int prev){
        if(i==k){
            ans.push_back(temp);return;
        }
        for(int j = prev + 1;j <= n;j++){
            if(k - i > n - j + 1)return;
            temp.push_back(j);
            solve(i + 1,n,k,j);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(0,n,k,0);
        return ans;
    }
};