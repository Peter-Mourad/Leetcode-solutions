class Solution {
public:
    int arrangeCoins(int n) {
        // for n rows the sum of coins = n * (n + 1) / 2
        long long l = 1, r = 1e9, mid, ans = 1;
        while(l <= r){
            mid = (l + r) >> 1;
            if(mid * (mid + 1) / 2 <= n)
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        return ans;
    }
};