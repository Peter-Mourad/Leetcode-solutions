class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0, pow = 1, mx = 0;
        while(num){
            ans += (num % 10) * pow;
            if(num % 10==6)
                mx = pow * 3;
            num/=10, pow *= 10;
        }
        return ans + mx;
    }
};