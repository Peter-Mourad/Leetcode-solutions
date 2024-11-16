class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int l = 1, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(citations[n - mid] >= mid)
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        return ans;
    }
};