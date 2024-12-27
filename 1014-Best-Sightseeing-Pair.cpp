class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = 0;
        for(int i = 0;i < values.size();i++){
            if(i)
                ans = max(ans, values[i] - i + mx);
            mx = max(mx, values[i] + i);
        }
        return ans;
    }
};