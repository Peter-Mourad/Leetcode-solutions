#define ll long long
class Solution {
public:
    ll gcd(ll a, ll b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }
    ll count(ll mid, int a, int b, int c){
        return mid / a + mid / b + mid / c - mid / lcm(a,b) - mid / lcm(a,c) - mid / lcm(b,c) + mid / lcm(a, lcm(b,c));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = 0, r = 1e14, mid, ans;
        while(l <= r){
            mid = (l + r) / 2;
            if(count(mid, a, b, c) >= n)
                r = mid - 1, ans = mid;
            else 
                l = mid + 1;
        }
        return ans;
    }
};