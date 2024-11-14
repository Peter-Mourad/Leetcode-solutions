class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end());
        int l = 1, r = quantities.back(), mid, ans = INT_MAX;
        while(l <= r){
            mid = (l + r) / 2;
            long have = 0;
            for(int i = 0;i < quantities.size();i++){
                have += (quantities[i] + mid - 1) / mid;
            }
            if(have <= n)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return ans;
    }
};