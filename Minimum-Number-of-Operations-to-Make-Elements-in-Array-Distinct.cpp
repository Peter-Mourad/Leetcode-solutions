class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> f(101);
        for(int i = nums.size() - 1;~i;i--){
            f[nums[i]]++;
            if(f[nums[i]] > 1){
                // need i + 1 prefix to be removed
                return (i + 1) / 3 + ((i + 1) % 3 ? 1 : 0);
            }
        }
        return 0;
    }
};