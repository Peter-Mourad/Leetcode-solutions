class Solution {
public:
    int longestStrChain(vector<string>& x) {
        auto comp = [](string p1,string p2) -> bool{
            return p1.size() < p2.size();
        };
        
        sort(x.begin(), x.end(), comp);
        vector<int> dp(x.size(), 1);
        for(int i = 1;i < x.size();i++){
            for(int j = 0;j < i;j++){
                if(x[i].size()!=x[j].size() + 1)continue;
                int k = 0,k2 = 0;
                for(;k < x[i].size();k++){
                    if(x[i][k]==x[j][k2])
                        k2++;
                }
                if(k2==x[j].size()){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};