class Solution {
public:
    int solve(int mask, int x, int &n, int &k, vector<int> &strength){
        if(mask == (1<<n) - 1) 
            return 0;
        int mn = INT_MAX;
        for(int i = 0;i < n;i++){
            int bit = 1<<i;
            if(!(mask & bit)){
                mask ^= bit;
                mn = min(mn, solve(mask, x + k, n, k, strength) + 
                (strength[i] + x - 1) / x);
                mask ^= bit;
            }
        }
        return mn;
    }
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        return solve(0, 1, n, k, strength);
    }
};