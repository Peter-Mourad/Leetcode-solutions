class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(), nums1.end());
        int sz = nums1.size();
        if(nums1.size() & 1)
            return double((nums1[sz>>1]));
        else{
            double ans = nums1[(sz>>1) - 1] + nums1[(sz>>1)];
            return ans / 2;
        }
    }
};