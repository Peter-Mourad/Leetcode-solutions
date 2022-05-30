class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MIN && b==-1)
            return INT_MAX;
        if(a / b < 0)
            return ceil(a / (b * 1.0));        
        else
            return a / b;
    }
};