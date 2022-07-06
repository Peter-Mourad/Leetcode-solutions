class Solution {
public:
    int fib(int n) {
        if(n < 2)return n;
        long long fib[n + 1];
        fib[0] = 0,fib[1] = 1;
        for(int i = 2;i<=n;i++)
            fib[i] = fib[i - 1] + fib[i - 2];
        return fib[n];
    }
};