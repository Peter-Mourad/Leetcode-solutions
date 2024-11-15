class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> suff;
        int pref = 0;
        for(int i = 1;i < n;i++){
            if(arr[i] >= arr[i - 1])
                pref = i;
            else break;
        }
        if(pref==n - 1) 
            return 0;

        for(int i = n - 1; ~i; i--){
            if(suff.empty() || (!suff.empty() && suff.back() >= arr[i]))
                suff.push_back(arr[i]);
            else break;
        }
        reverse(suff.begin(), suff.end());
        int ans = n - max(pref + 1, (int)suff.size());
        for(int i = 0;i <= pref;i++){
            int rem = n - i - 1;
            int l = lower_bound(suff.begin(), suff.end(), arr[i]) - suff.begin();
            int sz = suff.size() - l;
            ans = min(ans, n - min(rem, sz) - i - 1);
        }
        return ans;
    }
};