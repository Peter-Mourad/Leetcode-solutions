class Solution {
public:
    bool ok(int mid, string s, int ops){
        int need = 0, cur = 1;
        char last = s[0];
        for(int i = 1;i < s.size();i++){
            if(s[i]==last) cur++;
            else cur = 1, last = s[i];
            if(cur > mid){
                cur = 1;
                if(i < s.size() - 1 && s[i + 1]==last)
                    last = !(s[i] - '0') + '0';
                need++;
            }
        }
        // cout<<mid<<' '<<need<<endl;
        return ops >= need;
    }

    int minLength(string s, int numOps) {
        int need1 = 0, need2 = 0, bit1 = 0, bit2 = 1;
        for(int i = 0;i < s.size();i++){
            if(s[i] - '0'!=bit1) need1++;
            if(s[i] - '0'!=bit2) need2++;
            bit1^=1, bit2^=1;
        }
        if(need1 <= numOps || need2 <= numOps) return 1;

        int n = s.size();
        int l = 2, r = n, mid, ans = n;
        while(l <= r){
            mid = (l + r) >> 1;
            if(ok(mid, s, numOps))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return ans; 
    }
};