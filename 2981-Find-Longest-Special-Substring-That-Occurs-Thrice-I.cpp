class Solution {
public:
    bool ok(int sz, vector<vector<int>> &subs){
        for(int i = 0;i < 26;i++){
            int cur = 0;
            for(int j = 0;j < subs[i].size() && cur < 3;j++){
                if(subs[i][j] >= sz)
                    cur += subs[i][j] - sz + 1;
            }
            if(cur >= 3) return true;
        }
        return false;
    }
    int maximumLength(string s) {
        vector<vector<int>> subs(26);
        for(int i = 0;i < s.size(); ){
            int j = i;
            while(j < s.size() && s[i]==s[j]) j++;
            subs[s[i] - 'a'].push_back(j - i);
            i = j;
        }
        
        int l = 1,r = 100, mid, ans = -1;
        while(l <= r){
            mid = (l + r) >> 1;
            if(ok(mid, subs)) 
                l = mid + 1, ans = mid;
            else 
                r = mid - 1;
        }
        return ans;
    }
};