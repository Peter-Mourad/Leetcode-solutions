class Solution {
public:
    pair<int,int> t[2000000];
    void build(int i, int l, int r, vector<int> &x){
        if(l == r) {
            t[i] = {l, x[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2 + 1, l, mid, x);
        build(i * 2 + 2, mid + 1, r, x);
        t[i] = (t[i * 2 + 1].second >= t[i * 2 + 2].second) ? t[i * 2 + 1] : t[i * 2 + 2];
    }

    pair<int,int> query(int i, int l, int r, int s, int e){
        if(l > e || r < s) return {-1,-1};
        if(l >= s && r <= e) return t[i];
        int mid = (l + r) / 2;
        pair<int,int> left = query(i * 2 + 1, l, mid, s, e);
        pair<int,int> right = query(i * 2 + 2, mid + 1, r, s, e);
        return (left.second >= right.second) ? left : right;
    }

    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        build(0, 0, n - 1, height);
        pair<int,int> mx = query(0,0,n - 1,0,n - 1);
        // solve right part
        pair<int,int> mx1 = mx;
        while(mx1.first + 1 < n){
            pair<int,int> mx2 = query(0,0,n - 1,mx1.first + 1,n - 1);
            for(int i = mx1.first + 1; i < mx2.first; i++)
                ans += mx2.second - height[i];
            mx1 = mx2;
        }

        // solve left part
        mx1 = mx;
        while(mx1.first - 1 >= 0){
            pair<int,int> mx2 = query(0,0,n - 1,0,mx1.first - 1);
            for(int i = mx2.first + 1; i < mx1.first; i++)
                ans += mx2.second - height[i];
            mx1 = mx2;
        }
        return ans;
    }
};