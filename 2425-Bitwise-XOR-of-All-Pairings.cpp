class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if(nums2.size() & 1){
            for(auto a: nums1)
                ans ^= a;
        }
        if(nums1.size() & 1){
            for(auto a: nums2)
                ans ^= a;
        }
        return ans;
    }
};