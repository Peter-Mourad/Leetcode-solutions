class Solution {
public:
    vector<int> ans;
    void solve(int ind, int &n, vector<int> &cur, vector<bool> &have){
        if(!ans.empty()) return;
        while(ind < cur.size() && cur[ind])
            ind++;
        if(ind==cur.size()){
            ans = cur;
            return;
        }
        
        for(int a = n;a >= 1 && ans.empty(); a--){
            if(!have[a]) continue;
            if(a==1){
                cur[ind] = 1, have[1] = 0;
                solve(ind + 1, n, cur, have);
                cur[ind] = 0, have[1] = 1;
                continue;
            }
            if(ind + a < cur.size() && !cur[ind + a]){
                cur[ind] = cur[ind + a] = a, have[a] = 0;
                solve(ind + 1, n, cur, have);
                cur[ind] = cur[ind + a] = 0, have[a] = 1;
            }
        }
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> cur(n * 2 - 1);
        vector<bool> have(n + 1, 1);
        solve(0, n, cur, have);
        return ans;
    }
};