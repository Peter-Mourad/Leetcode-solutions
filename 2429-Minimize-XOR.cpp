class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int> unset;
        int need = __builtin_popcount(num2), res = 0;
        for(int i = 30; i >= 0; i--){
            int bit = 1<<i;
            if(!(num1 & bit))
                unset.push_back(bit);
            else if(need-- > 0)
                res += bit;
        }
        sort(unset.begin(), unset.end());
        int i = 0;
        while(need-- > 0)
            res += unset[i++];
        
        return res;
    }
};