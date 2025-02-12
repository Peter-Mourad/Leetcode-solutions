class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int> > sum_of_digits;
        for(auto a: nums){
            int sum = 0, temp = a;
            while(temp){
                sum += temp % 10;
                temp/=10;
            }
            sum_of_digits[sum].push_back(a);
        }
        int ans = -1;
        for(auto [sum, v]: sum_of_digits){
            if(v.size()==1) continue;
            sort(v.begin(),v.end());
            ans = max(ans, v.back() + v[v.size() - 2]);
        }
        return ans;
    }
};