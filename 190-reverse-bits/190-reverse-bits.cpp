class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0,j = 31;i < 16;i++){
            if((((1<<i) & n) ? 1 : 0)!=(((1<<(31 - i)) & n) ? 1: 0)){
                if((1<<i) & n)
                    n-=(1<<i),n+=(1<<(31 - i));
                else
                    n+=(1<<i),n-=(1<<(31 - i));
            }
        }
        return n;
    }
};