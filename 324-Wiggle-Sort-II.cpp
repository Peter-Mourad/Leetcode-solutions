class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1(nums);
        sort(nums1.begin(), nums1.end());
        for(int i = n - 1, j = 0, k = (n - 1) / 2 + 1; ~i; i--){
            nums[i] = (i & 1) ? nums1[k++] : nums1[j++];
        }
    }
};