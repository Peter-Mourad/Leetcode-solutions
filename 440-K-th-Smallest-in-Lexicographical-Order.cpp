class Solution {
public:
    int findKthNumber(int n, int k) {
        k--;
        int pref = 1;
        while(k > 0)   {
            int cnt = countValidSuff(pref, n);
            if(k >= cnt) pref++, k-=cnt;
            else pref *= 10, k--;
        }
        return pref;
    }

private:
    int countValidSuff(int pref, long n){
        long cur = pref, next = pref + 1, total = 0;
        while(cur <= n){
            total += min(n + 1, next) - cur;
            cur *= 10, next *= 10;
        }
        return total;
    }
};