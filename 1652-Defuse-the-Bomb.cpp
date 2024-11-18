class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(!k){
            return vector<int>(n);
        }
        
        vector<int> pref(n + 1);
        for(int i = 0;i < n;i++){
            pref[i + 1] = pref[i] + code[i];
        }
        vector<int> ans(n);
        for(int i = 0;i < n;i++){
            if(k > 0){
                int r = min(n, k + i + 1);
                ans[i] += pref[r] - pref[i + 1];
                if(k + i >= n)
                    ans[i] += pref[(k + i) % n + 1];
            }
            else{
                int l = max(0, i - abs(k));
                ans[i] += pref[i] - pref[l];
                if(abs(k) > i)
                    ans[i] += pref[n] - pref[n - abs(k) + i];
            }
        }
        return ans;
    }
};