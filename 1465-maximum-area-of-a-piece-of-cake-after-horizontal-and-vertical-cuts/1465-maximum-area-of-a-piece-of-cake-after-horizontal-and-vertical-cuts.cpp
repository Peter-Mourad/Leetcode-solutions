#define ll long long
const int mod = 1e9 + 7;
class Solution {
public:
    ll maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(verticalCuts.begin(), verticalCuts.end());
        ll mx = verticalCuts[0];
        for(int i = 1;i < verticalCuts.size();i++)
            mx = max(mx,1ll * verticalCuts[i] - verticalCuts[i - 1]);
        mx = max(mx, 1ll * w - verticalCuts.back());
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        ll mx2 = horizontalCuts[0];
        for(int i = 1;i<horizontalCuts.size();i++)
            mx2 = max(mx2, 1ll * horizontalCuts[i] - horizontalCuts[i - 1]);
        mx2 = max(mx2, 1ll * h - horizontalCuts.back());
        int ans = (mx % mod) * (mx2 % mod) % mod;
        return ans;
    }
};