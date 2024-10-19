class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem[3];
        for(auto &a: nums){
            rem[a % 3].push_back(a);
            sum+=a;
        }
        if(!(sum % 3))
            return sum;

        for(int i = 1;i < 3;i++)
            sort(rem[i].begin(), rem[i].end());

        int mn = INT_MAX;
        if(sum % 3==1){
            if(rem[1].size()) mn = rem[1][0];
            if(rem[2].size() > 1) mn = min(mn, rem[2][0] + rem[2][1]);
        }
        if(sum % 3==2){
            if(rem[1].size() > 1) mn = rem[1][0] + rem[1][1];
            if(rem[2].size()) mn = min(mn, rem[2][0]);
        }
        return sum - mn;
    }
};