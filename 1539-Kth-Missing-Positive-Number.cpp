class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 1,r = 2000, mid, ans = 1;
        // binary search on the number see how many numbers less than mid
        // if mid - count(numbers < mid) == k -> mid is the answer
        while(l <= r){
            mid = (l + r) >> 1;
            int ind = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            if(mid - ind < k)
                l = mid + 1;
            else
                r = mid - 1, ans = mid;
        }
        return ans;
    }
};