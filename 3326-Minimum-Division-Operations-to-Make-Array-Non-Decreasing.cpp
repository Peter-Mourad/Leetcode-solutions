class Solution {
public:
    vector<int> properDivisor;

    Solution(){
        properDivisor = vector<int> (1000001);
    }

    int getProperDivisor(int &a){
        for(int i = 2;i * i <= a; i++){
            if(a % i==0)
                return properDivisor[a] = max(i, a / i);
        }
        return properDivisor[a] = 1;
    }

    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = nums.size() - 2; ~i; i--){
            while(nums[i] > nums[i + 1]){
                if(!properDivisor[nums[i]])
                    getProperDivisor(nums[i]);
                if(properDivisor[nums[i]]==1)break;
                nums[i] /= properDivisor[nums[i]], ans++;
            }
            if(nums[i] > nums[i + 1])return -1;
        }
        return ans;
    }
};