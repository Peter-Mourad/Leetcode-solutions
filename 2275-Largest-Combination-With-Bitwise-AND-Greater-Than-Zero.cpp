class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitFreq(31);
        for(auto c: candidates){
            for(int j = 0;j < 31;j++){
                if((1 << j) & c)
                    bitFreq[j]++;
            }
        }
        int ans = 1;
        for(int i = 0;i < 31;i++)
            ans = max(ans, bitFreq[i]);
        return ans;
    }
};