class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long ans = x;
        for(long long i = 0;i < 56;i++){
            long long bit = ((long long)1<<i);
            if(bit & x) continue;
            if(n & 1) ans += bit;
            n >>= 1;
        }
        return ans;
    }
};