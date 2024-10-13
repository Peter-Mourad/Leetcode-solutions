class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto &a : nums){
            int sum = 0;
            string s = to_string(a);
            for(auto &ch: s)
                sum += ch - '0';
            
            ans = min(ans, sum);
        }
        return ans;
    }
};