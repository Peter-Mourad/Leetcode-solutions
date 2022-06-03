class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (__builtin_popcount(n)==1 && n >= 1);
    }
};