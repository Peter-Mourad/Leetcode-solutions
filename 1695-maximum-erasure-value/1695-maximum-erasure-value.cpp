class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int cur= 0,l = 0,ans = 0;
        map<int,int> f;
        for(int i = 0;i < nums.size();i++){
            cur+=nums[i];
            f[nums[i]]++;
            while(f[nums[i]]==2){
                f[nums[l]]--;
                cur-=nums[l++];
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};