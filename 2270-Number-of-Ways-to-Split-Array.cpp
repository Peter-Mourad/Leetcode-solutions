
#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& x) {
        int n = x.size();
        vector<ll>pref(n + 1);
        for(int i = 0;i < n;i++){
            pref[i + 1] = pref[i] + x[i];
        }
        int ans = 0;
        for(int i = 0;i < n - 1;i++){
            // take from <= i and after i
            if(pref[i + 1] >= pref[n] - pref[i + 1])ans++;
        }
        return  ans;
    }
};