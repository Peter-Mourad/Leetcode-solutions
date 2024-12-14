class Solution {
public:
    static long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        map<int, int> taken;
        for(int l=0, r=0; r < n; r++){
            taken[nums[r]]++;
            while(l < r && prev(taken.end())->first - taken.begin()->first > 2){
                if(!--taken[nums[l]])
                     taken.erase(nums[l]);
                l++;
            }
            cnt += r - l + 1LL;
        }
        return cnt;
    }
};