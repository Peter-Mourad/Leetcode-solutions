class Solution {
public:
    int to_int(string &a){
        int res = 0;
        for(int i = a.size() - 1,pow = 1;~i;i--,pow*=2){
            if(a[i]=='1')
                res+=pow;
        }
        return res;
    }
    bool hasAllCodes(string s, int k) {
        string temp = "";
        map<int,bool>mp;
        for(int i = 0;i < s.size();i++){
            temp+=s[i];
            if(temp.size()==k){
                mp[to_int(temp)] = 1;
                temp = temp.substr(1,temp.size());
            }
        }
        return mp.size()==(1<<k);
    }
};