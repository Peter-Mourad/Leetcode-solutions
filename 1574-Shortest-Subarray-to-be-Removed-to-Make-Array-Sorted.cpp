class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int pref = 0;
        for(int i = 1;i < n;i++){
            if(arr[i] >= arr[i - 1])
                pref = i;
            else break;
        }
        if(pref==n - 1) 
            return 0;
        
        int suff = n - 1;
        for(int i = n - 2; ~i; i--){
            if(arr[i] <= arr[i + 1])
                suff = i;
            else break;
        }
        int ans = min(n - pref - 1, suff);
        for(int i = 0, j = suff;i <= pref && j < n;){
            if(arr[i] <= arr[j])
                ans = min(ans, j - i++ - 1);
            else
                j++;
        }
        return ans;
    }
};