class Solution {
public:
    int setBits(int a){
        int res = 0;
        while(a){
            res += a & 1;
            a >>= 1;
        }
        return res;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;){
            int j = i, bits = setBits(nums[i]);
            while(j < n && setBits(nums[j])==bits)
                j++;
            sort(nums.begin() + i, nums.begin() + j);
            i = j;
        }
        for(int i = 1;i < n;i++){
            if(nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
};