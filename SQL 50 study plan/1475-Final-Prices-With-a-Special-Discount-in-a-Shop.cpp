class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        for(int i = 0;i < n; i++){
            int temp = -1e8;
            for(int j = i + 1; j < n; j++){
                if(prices[j] <= prices[i]){
                    temp = prices[j];
                    break;
                }
            }
            ans[i] = min(prices[i], prices[i] - temp);
        }
        return ans;
    }
};